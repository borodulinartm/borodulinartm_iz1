#ifndef BORODULINARTM_IZ1_REBUILDER_MASS_H
#define BORODULINARTM_IZ1_REBUILDER_MASS_H

#define SIZE_MASS 5

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct dynamic_array {
    size_t size_mass;
    int *mass;
} dynamic_array_t;

// Вывод массива
void print_mass(dynamic_array_t *data);
int input_data(dynamic_array_t *data, int *sizes_of_vectors);
dynamic_array_t *rebuild_mass(dynamic_array_t *data, size_t new_size);

#endif //BORODULINARTM_IZ1_REBUILDER_MASS_H
