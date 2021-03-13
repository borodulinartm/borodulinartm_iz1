#include <gtest/gtest.h>

#include <iostream>

extern "C" {
#include "rebuilder_mass.h"
#include "rebuilder_mass.c"
}

const char *test_inputing = "../tests/1.tst";

// Сравнивает 2 массива. Если хоть один элемент не совпадает, то тест не пройден
int compare_mass(int **expected, dynamic_array_t *received, const int *sizes) {
    for(size_t i = 0; i < SIZE_MASS; ++i) {
        for(size_t j = 0; j < sizes[i]; ++j) {
            if (expected[i][j] != received[i].mass[j]) {
                return 0;
            }
        }
        // Если получили выравненный массив
        if (sizes[i] < received[i].size_mass) {
            for(size_t j = sizes[i]; j < received[i].size_mass; ++j) {
                if (received[i].mass[j] != 0) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

// Извлекаем пример массива из входных данных
int fill(int **arr, int *sizes, const char *file_name) {
    FILE *file = fopen(file_name, "r");
    int index = 0, max_size = 0;

    // Если файла нет/произошли другие ошибки
    if (!file) {
        return -1;
    }

    // Читаем входные данные в файл
    while (!feof(file)) {
        if (fscanf(file, "%d", &sizes[index]) == 1) {

            if (sizes[index] > max_size) {
                max_size = sizes[index];
            }

            arr[index] = new int[sizes[index]];
            for(size_t j = 0; j < sizes[index]; ++j) {
                fscanf(file, "%d", &arr[index][j]);
            }
        }
        ++index;
    }

    fclose(file);
    return max_size;
}

// Тестирование ввода данных
TEST(input_testing, input_data) {
    int *array[SIZE_MASS];
    int sizes[SIZE_MASS];

    fill(array, sizes, test_inputing);

    dynamic_array_t rec_mass[SIZE_MASS];
    input_data(rec_mass, sizes);

    // Если значения элементов массива заполнены корректно, то тест пройден
    ASSERT_EQ(compare_mass(array, rec_mass, sizes), 1);

    for(size_t i = 0; i < SIZE_MASS; ++i) {
        delete[] array[i];
        free(rec_mass[i].mass);
    }
}

// Тестирование ребилдинга данных
TEST(rebuilding_test, rebuild_mass) {
    int *array[SIZE_MASS];
    int sizes[SIZE_MASS];

    int size = fill(array, sizes, test_inputing);

    auto *rec_mass = new dynamic_array_t[SIZE_MASS];
    input_data(rec_mass, sizes);
    rec_mass = rebuild_mass(rec_mass, size);

    // Если значения элементов массива заполнены корректно, то тест пройден
    ASSERT_EQ(compare_mass(array, rec_mass, sizes), 1);

    for(size_t i = 0; i < SIZE_MASS; ++i) {
        delete[] array[i];
        free(rec_mass[i].mass);
    }

    delete[] rec_mass;
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}