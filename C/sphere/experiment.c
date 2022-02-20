
#undef __STRICT_ANSI__  /* To use the math constants from math.h in a code compiled with the MinGW gcc. */

#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include "mersenne.h"
#include "simulations.h"
#include "experiment.h"

double volume(unsigned int layer) {

    double r = (double)layer * (RADIUS/LAYERS);

    return (4.0 * M_PI * (pow((r + (RADIUS/LAYERS)), 3.0) - pow(r, 3.0)))/3.0;

}

void sphere(const unsigned long his, const unsigned long rep, result *const results) {

    unsigned long n;
    medium sphere;
    neutron particle;

    double  n_collisions[LAYERS], /* Stores the number of collisions that occurred in each layer of the sphere. */
            d;                    /* Variable to keep track of the distance between a particle and the source.  */
            

    for(unsigned long r = 0; r < rep; r++) {

        n = his;
        for(unsigned int l = 0; l < LAYERS; l++) {
            n_collisions[l] = 0.0;
        }

        for(unsigned long h = 0; h < n; h++) {

            punctual_source(&particle);
            init_cross_sections(&particle, &sphere, 0.0, 0);

            while(true) {
                
                select_path(&particle, &sphere);

                d = DISTANCE(particle.x, particle.y, particle.z);
                unsigned int curr_layer = (unsigned int)d * (LAYERS/RADIUS);  
                    
                if(curr_layer >= LAYERS) break;

                init_cross_sections(&particle, &sphere, d, curr_layer);
                select_interaction(&particle, &sphere, &n);
  
                n_collisions[curr_layer]++; 

                if(particle.energy <= THERMAL_ENERGY) break;

            }

        }

        double total_flux, layer_r;

        if(rep > 1) {
            for(unsigned int l = 0; l < LAYERS; l++) {

                results->n_coll_mean[l] += n_collisions[l];
                results->n_coll_dev[l] += SQUARE(n_collisions[l]);

                layer_r = l * (RADIUS/LAYERS);
                if(layer_r < (RADIUS/FUEL_PART))
                    total_flux = n_collisions[l]/volume(l)/n/FUEL_TCS;
                else if(layer_r <= RADIUS)
                    total_flux = n_collisions[l]/volume(l)/n/MOD_TCS;

                results->flux_mean[l] += total_flux;
                results->flux_dev[l] += SQUARE(total_flux);
                
            }
        }
        else {
            for(unsigned int l = 0; l < LAYERS; l++) {

                results->n_coll_mean[l] += n_collisions[l];
                
                layer_r = l * (RADIUS/LAYERS);
                if(layer_r < (RADIUS/FUEL_PART))
                    total_flux = n_collisions[l]/volume(l)/n/FUEL_TCS;
                else if(layer_r <= RADIUS)
                    total_flux = n_collisions[l]/volume(l)/n/MOD_TCS;

                results->flux_mean[l] += total_flux;
                
            }
        }

    }

    if(rep > 1) {
        for(unsigned int l = 0; l < LAYERS; l++) {
            results->n_coll_mean[l] /= rep;
            results->flux_mean[l] /= rep;
            results->n_coll_dev[l] = sqrt((results->n_coll_dev[l]/rep) - SQUARE(results->n_coll_mean[l]))/(rep - 1);
            results->flux_dev[l] = sqrt((results->flux_dev[l]/rep) - SQUARE(results->flux_mean[l]))/(rep - 1);
        }
    }
    else {
        for(unsigned int l = 0; l < LAYERS; l++) {
            results->n_coll_mean[l] /= rep;
            results->flux_mean[l] /= rep;
        }
    }

}