#ifndef SIMULATIONS_H
#define SIMULATIONS_H

#define SQUARE(x) ((x)*(x))
#define ABS(x) ((x) >= 0.0 ? (x) : (-(x)))

// Particles mass number and thermal energy:
#define N_MASS_NUM 1.00000e0
#define THERMAL_ENERGY 5.00000e-1

// Fuel (U-235) mass number and cross-sections:
#define FUEL_MASS_NUM 2.35000e2
#define FUEL_TCS 4.00000e0
#define FUEL_FCS 1.00000e-1
#define FUEL_ESCS 2.5000e0
#define FUEL_ISCS 1.0000e0
#define FUEL_ACS 4.00000e-1
#define FISSION_NEUTRONS 2.43000e0 /* Average number of neutrons emitted after a fission event. */

// Moderator (H20-18) mass number and cross-sections:
#define MOD_MASS_NUM 1.80000e1
#define MOD_TCS 1.50000e0
#define MOD_ESCS 4.00000e-1
#define MOD_ISCS 1.00000e-0
#define MOD_ACS 1.00000e-1

// Medium properties:
typedef struct {
    double m_num;           /* Number of mass of the material.                          */
    double t_cs;            /* Total cross-section of the material.                     */
    double el_cs;           /* Cross-section for elastic scattering.                    */
    double inl_cs;          /* Cross-section for inelastic scattering.                  */
    double fission_cs;      /* Fission cross-section of the fuel.                       */
    double abs_cs;          /* Absorption cross-section of the fuel.                    */
    double n_fission;       /* Average number of neutrons emitted in fission events.    */
} fuel;

typedef struct {
    double m_num;           /* Number of mass of the material.                          */
    double t_cs;            /* Total cross-section of the material.                     */
    double el_cs;           /* Cross-section for elastic scattering.                    */
    double inl_cs;          /* Cross-section for inelastic scattering.                  */
    double abs_cs;          /* Absorption cross-section of the moderator.               */
} moderator;

typedef enum {
    FUEL,
    MODERATOR
} region;     /* Tag to identify regions. */

typedef union {
    fuel u_diox;       /* Fuel simulated in the experiment (uranium dioxide).   */
    moderator water;   /* Moderator simulated in the experiment.                */
} material;

typedef struct {
    region tag;
    material comp; 
} medium;

// Particles states:
typedef struct {
    double x, y, z;     /* Cartesian coordinates of the particle position.                              */
    double u, v, w;     /* Direction vector of the particle where.                                      */
    double in, out;     /* Variables to keep check if the particle is getting out of a region bound.    */
    double energy;      /* Energy of the particle.                                                      */
} neutron;

// Functions for the simulation of particles histories:

/*
    ini_cross_sections:     Given the particle coordinates in the phase space, compute 
                            the cross sections of the material in the surroundings.
*/
void init_cross_sections(const neutron *const particle, medium *const slabs);

/*
    check_path:     Given the location of the particle in the medium and its
                    current direction, checks if the particle is entering or 
                    leaving a region.
*/
bool check_path(neutron *const particle, const medium *const slabs);

/*
    select_path:    Given the location of the particle in the medium, selects 
                    the walk of the particle to the site where its next
                    interaction with the medium will happen.
*/
void select_path(neutron *const particle, const medium *const slabs);

/*
    select_interaction:     Given the location of the particle in the medium, selects a
                            a interaction for it with some nuclide in the surroundings.
                            Returns a token that identifies the interaction selected.
*/
char select_interaction(neutron *const particle, const medium *const slabs, unsigned long *const n);

/*
    direction_after_scattering:     Selects the new direction of a neutron 
                                    after a collision event using a rejection
                                    method.                            
*/
void direction_after_colission(neutron *const particle, double cos_theta);

/*
    iso_elastic_scattering:     Simulates the scattering of particles, that takes 
                                place after collisions events, with the assumption that the 
                                distribution of the new direction after a non-absorption 
                                interaction is isotropic. For simplicity, the cosine of the 
                                angle of the collision is selected from de elastic scattering 
                                model by default. If a inelastic collision was selected, the
                                energy of the particle is reduced by a factor depending on the
                                target element.  
*/
void iso_scattering(neutron *const particle, const double target_mass, bool inelastic);

/*
    punctual_source:    Simulates the emission of particles by a punctual source 
                        located in a selected point of the sistem. 
*/
void punctual_source(neutron *const particle);

#endif