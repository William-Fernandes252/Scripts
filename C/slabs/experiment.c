#undef __STRICT_ANSI__

#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include "mersenne.h"
#include "simulations.h"
#include "experiment.h"

void slabs(const unsigned long his, const unsigned long rep, result *const results) {

    medium slabs;
    neutron particle;
    unsigned long n;
    char interaction;

    double  moderations,
            absorptions,
            reflections,
            escapes; 

    for(int r = 0; r < rep; r++) {
        
        n = his;

        moderations = 0;
        absorptions = 0;
        reflections = 0;
        escapes     = 0;

        for(int h = 1; h <= n; h++) {

            punctual_source(&particle);
            init_cross_sections(&particle, &slabs);

            while(0.0 <= particle.z && particle.z <= MODERATOR_SLAB_LIMIT) {

                select_path(&particle, &slabs);

                if(particle.z < 0.0) {
                    reflections++;
                    break;
                }
                else if(MODERATOR_SLAB_LIMIT < particle.z) {
                    escapes++;
                    break;
                }

                init_cross_sections(&particle, &slabs);
                interaction = select_interaction(&particle, &slabs, &n);
                if(interaction == 'a' || interaction == 'f') {
                    absorptions++;
                    break;
                }
                assert(interaction != '!');


                if(particle.energy <= THERMAL_ENERGY) {
                    moderations++;
                    break;
                }

            }

        } 
        
        results->mod_m += moderations;
        results->abs_m += absorptions;
        results->ref_m += reflections;
        results->esc_m += escapes;
        results->mod_frac_m += moderations/n;
        results->abs_frac_m += absorptions/n;
        results->ref_frac_m += reflections/n;
        results->esc_frac_m += escapes/n;
        results->hist_m += (double)n;

        if(rep > 1) {
            results->mod_d += SQUARE(moderations);
            results->abs_d += SQUARE(absorptions);
            results->ref_d += SQUARE(reflections);
            results->esc_d += SQUARE(escapes);
            results->mod_frac_d += SQUARE(moderations/n);
            results->abs_frac_d += SQUARE(absorptions/n);
            results->ref_frac_d += SQUARE(reflections/n);
            results->esc_frac_d += SQUARE(escapes/n);
            results->hist_d += (double)n;
            results->hist_d += SQUARE((double)n);
        }

    }

    // Mean of the number and the relative number of occurrences of each type of interaction and of the number of histories followed in each repetition of the experiment:
    results->mod_m /= rep;
    results->abs_m /= rep;
    results->ref_m /= rep;
    results->esc_m /= rep;
    results->mod_frac_m /= rep;
    results->abs_frac_m /= rep;
    results->ref_frac_m /= rep;
    results->esc_frac_m /= rep;
    results->hist_m /= rep;

    if(rep > 1) {
        // Standard deviation:
        results->mod_d = sqrt((results->mod_d/rep) - SQUARE(results->mod_m))/(rep - 1);
        results->abs_d = sqrt((results->abs_d/rep) - SQUARE(results->abs_m))/(rep - 1);
        results->ref_d = sqrt((results->ref_d/rep) - SQUARE(results->ref_m))/(rep - 1);
        results->esc_d = sqrt((results->esc_d/rep) - SQUARE(results->esc_m))/(rep - 1);
        results->mod_frac_d = sqrt((results->mod_frac_d/rep) - SQUARE(results->mod_frac_m))/(rep - 1);
        results->abs_frac_d = sqrt((results->abs_frac_d/rep) - SQUARE(results->abs_frac_m))/(rep - 1);
        results->ref_frac_d = sqrt((results->ref_frac_d/rep) - SQUARE(results->ref_frac_m))/(rep - 1);
        results->esc_frac_d = sqrt((results->esc_frac_d/rep) - SQUARE(results->esc_frac_m))/(rep - 1);
        results->hist_d = sqrt((results->hist_d/rep) - SQUARE(results->hist_m))/(rep - 1);
    }

}