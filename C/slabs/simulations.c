#undef __STRICT_ANSI__

#include <math.h>
#include <stdbool.h>
#include "mersenne.h"
#include "simulations.h"
#include "experiment.h"

void init_cross_sections(const neutron *const particle, medium *const slabs) {

    if(particle->z <= FUEL_SLAB_LIMIT) {
        slabs->tag = FUEL;
        slabs->comp.u_diox.m_num = FUEL_MASS_NUM;
        slabs->comp.u_diox.t_cs = FUEL_TCS;
        slabs->comp.u_diox.el_cs = FUEL_ESCS;
        slabs->comp.u_diox.inl_cs = FUEL_ISCS;
        slabs->comp.u_diox.fission_cs = FUEL_FCS;
        slabs->comp.u_diox.abs_cs = FUEL_ACS;
        slabs->comp.u_diox.n_fission = FISSION_NEUTRONS;
    }
    else if(particle->z <= MODERATOR_SLAB_LIMIT) {
        slabs->tag = MODERATOR;
        slabs->comp.water.m_num = MOD_MASS_NUM;
        slabs->comp.water.t_cs = MOD_TCS;
        slabs->comp.water.el_cs = MOD_ESCS;
        slabs->comp.water.inl_cs = MOD_ISCS;
        slabs->comp.water.abs_cs = MOD_ACS;
    }

}

bool check_path(neutron *const particle, const medium *const slabs) {

    double R_O, R_R, disc;

    R_O = (particle->x * particle->u) + (particle->y * particle->v) + (particle->z * particle->w);
    switch (slabs->tag) {
        case FUEL:
            R_R = SQUARE(particle->x) + SQUARE(particle->y) + SQUARE(particle->z) - SQUARE(FUEL_SLAB_LIMIT/2);
            break;
        case MODERATOR:
            R_R = SQUARE(particle->x) + SQUARE(particle->y) + SQUARE(particle->z) - SQUARE((MODERATOR_SLAB_LIMIT - FUEL_SLAB_LIMIT)/2);
            break;
    }    
    disc = SQUARE(R_O) - R_R;

    if(disc < 0) return false;

    particle->in = -R_O - sqrt(disc);
    particle->out = -R_O + sqrt(disc);

    if(particle->out < 0) return false;

    return true;
    
}

void select_path(neutron *const particle, const medium *const slabs) {

    double path_length;

    switch(slabs->tag) {
        case FUEL:
            path_length = -log(mersenne())/slabs->comp.u_diox.t_cs;
            break;
        case MODERATOR:
            path_length = -log(mersenne())/slabs->comp.water.t_cs;
            break;
    }

    if(check_path(particle, slabs))
        path_length += (particle->out - particle->in); 

    particle->x += particle->u * path_length;
    particle->y += particle->v * path_length;
    particle->z += particle->w * path_length;

}

char select_interaction(neutron *const particle, const medium *const slabs, unsigned long *const n) {

    double R, t;
    double  els_p,
            inls_p,
            abs_p,
            fission_p;  /* Probabilities of occurrence of the possible events. */

    if(0.0 <= particle->z) {

        R = mersenne();

        switch(slabs->tag) {

            case FUEL:
                t = slabs->comp.u_diox.t_cs;
                els_p = slabs->comp.u_diox.el_cs/t;
                inls_p = slabs->comp.u_diox.inl_cs/t;
                abs_p = slabs->comp.u_diox.abs_cs/t;
                fission_p = slabs->comp.u_diox.fission_cs/t;

                if(R < els_p) {
                    iso_scattering(particle, slabs->comp.u_diox.m_num, false);
                    return 'e';
                }
                else if(R < els_p + inls_p) {
                    iso_scattering(particle, slabs->comp.u_diox.m_num, true);
                    return 'i';
                }
                else if(R <= els_p + inls_p + abs_p) {
                    particle->energy = 0.0;
                    return 'a';
                }
                else if(R <= els_p + inls_p + abs_p + fission_p) {
                    R = mersenne();
                    if(R < ABS(2 - slabs->comp.u_diox.n_fission)) {
                        *n += 3;
                    }
                    else if(R <= ABS(2 - slabs->comp.u_diox.n_fission) + ABS(3 - slabs->comp.u_diox.n_fission)) {
                        *n += 2;
                    }   /* For simplicity, the fissions neutrons are emitted by the font. */
                    return 'f';
                }
                break;

            case MODERATOR:
                t = slabs->comp.water.t_cs;
                els_p = slabs->comp.water.el_cs/t;
                inls_p = slabs->comp.water.inl_cs/t;
                abs_p = slabs->comp.water.abs_cs/t;

                if(R < els_p) {
                    iso_scattering(particle, slabs->comp.water.m_num, false);
                    return 'e';
                }
                else if(R < els_p + inls_p) {
                    iso_scattering(particle, slabs->comp.water.m_num, true);
                    return 'i';
                }
                else if(R <= els_p + inls_p + abs_p) {
                    return 'a';
                }
                break;

        }

    }

    return '!'; /* Error token. */

}

void direction_after_colission(neutron *const particle, const double cos_theta) {

    double c1, c2, c3, c4, c5, sin_delta, cos_delta;
    double w_mod = ABS(particle->w);
    
    do {
        c1 = 2 * mersenne() - 1;
        c2 = 2 * mersenne() - 1;
        c3 = SQUARE(c1) + SQUARE(c2);
    } while(c3 - 1 > 0);

    c4 = sqrt(c3);
    sin_delta = c1/c4;
    cos_delta = c2/c4;
    c5 = sqrt(1 - SQUARE(cos_theta));
    
    if(1 - w_mod < 0.0) {
        particle->u = c5 * cos_delta;
        particle->v = c5 * sin_delta;
        particle->w = cos_theta * (particle->w/w_mod);
    }
    else {
        double c6 = sqrt(1 - SQUARE(particle->w));
        particle->u = particle->u * cos_theta + ((c5/c6) * (particle->u * particle->v * cos_delta - particle->v * sin_delta));
        particle->v = particle->v * cos_theta + ((c5/c6) * (particle->u * particle->v * cos_delta + particle->u * sin_delta));
        particle->w = (particle->w * cos_theta) - (c5 * c6 *cos_delta);
    }

}

void iso_scattering(neutron *const particle, const double target_mass, bool inelastic) {

    // Selection of the cosine of the angle of collision in the laboratory ref. from the angle in the center-of-mass ref.
    double cos_theta_cm = 1 - 2 * mersenne();
    double A = target_mass/N_MASS_NUM;
    double h = A * cos_theta_cm;
    double alfa2 = SQUARE((A-1)/(A+1));
    double cos_theta = (1 + h)/sqrt(1 + SQUARE(A) + 2 * h);

    direction_after_colission(particle, cos_theta);

    // Selection of the new energy.
    particle->energy = (particle->energy * ((1 - alfa2) * cos_theta_cm + 1 + alfa2))/2;

    if(inelastic) {
        if(target_mass == FUEL_MASS_NUM) particle->energy *= 0.65;
        if(target_mass == MOD_MASS_NUM) particle->energy *= 0.40;
    }

}

void punctual_source(neutron *const particle) {

    // Initial position, energy:
    particle->x = 0.0;
    particle->y = 0.0;
    particle->z = 0.0;
    particle->energy = 0.50e6; /* 0.5 MeV */

    // Selection of the initial direction:
    double cos_theta = 2.0 * mersenne() - 1.0;
    double phi       = 2 * M_PI * mersenne();
	double sin_theta = sqrt(1.0 - SQUARE(cos_theta));
    
    particle->u = cos(phi) * sin_theta;  
	particle->v = sin(phi) * sin_theta;  
	particle->w = cos_theta;

}