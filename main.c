#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "rebuilder_mass.h"

int main(int argc, char *argv[]) {
    //Это будет заменено на argv (в аргументах будут идти размеры массива)
    assert(argc - 1 == SIZE_MASS);

    int sizes[SIZE_MASS];
    for(int i = 1; i < argc; ++i) {
        sizes[i - 1] = atoi(argv[i]);
    }

    // Создаём массив указателей
    dynamic_array_t dynamic_array[SIZE_MASS];

    // Заполняем его
    size_t max_size = input_data(dynamic_array, sizes);
    printf("\n");

    dynamic_array_t *rebuilded_mass = rebuild_mass(dynamic_array, max_size);
    print_mass(rebuilded_mass);

    for(size_t i = 0; i < SIZE_MASS; ++i) {
        free(dynamic_array[i].mass);
    }
    return EXIT_SUCCESS;
}
