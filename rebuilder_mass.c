#include "rebuilder_mass.h"

void print_mass(dynamic_array_t *data) {
    for(int i = 0; i < SIZE_MASS; ++i) {
        for(int j = 0; j < data->size_mass; ++j) {
            printf("%d ", data[i].mass[j]);
        }
        printf("\n");
    }
}

dynamic_array_t *rebuild_mass(dynamic_array_t *data, size_t new_size) {
    printf("%zu\n", new_size);
    for(size_t i = 0; i < SIZE_MASS; ++i) {
        data[i].mass = (int*)realloc(data[i].mass, new_size * sizeof(int));

        for(size_t j = data[i].size_mass; j < new_size; ++j) {
            data[i].mass[j] = 0;
        }

        data[i].size_mass = new_size;
    }

    return data;
}

int input_data(dynamic_array_t *data, int *sizes_of_vectors) {
    int max_size = 0;
    for(size_t i = 0; i < SIZE_MASS; ++i) {
        assert(sizes_of_vectors[i] > 0);

        if (max_size < sizes_of_vectors[i]) {
            max_size = sizes_of_vectors[i];
        }

        data[i].mass = (int*) calloc(sizes_of_vectors[i], sizeof(int));
        data[i].size_mass = sizes_of_vectors[i];

        for (size_t j = 0; j < sizes_of_vectors[i]; ++j) {
            data[i].mass[j] = (int) i + 1;
            printf("%d ", data[i].mass[j]);
        }

        printf("\n");
    }
    return max_size;
}

