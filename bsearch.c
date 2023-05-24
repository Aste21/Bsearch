#include <stdio.h>

void* bsearch(const void* key, const void* base, size_t num, size_t size,
              int (*compar)(const void*, const void*))
{
    size_t left = 0;
    size_t right = num - 1;

    while (left <= right) {
        size_t middle = left + (right - left) / 2;
        const void* middle_element = (char*)base + (middle * size);
        int comparison_result = compar(key, middle_element);

        if (comparison_result == 0) {
            return (void*)middle_element;  // Match found
        }
        else if (comparison_result < 0) {
            right = middle - 1;  // Key is smaller, search in the left half
        }
        else {
            left = middle + 1;  // Key is larger, search in the right half
        }
    }

    return NULL;  // No match found
}

int compare_int(const void* a, const void* b)
{
    const int* key = (const int*)a;
    const int* element = (const int*)b;

    if (*key < *element) {
        return -1;  // Key is less than element
    }
    else if (*key > *element) {
        return 1;   // Key is greater than element
    }
    else {
        return 0;   // Key is equal to element
    }
}

int compare_char(const void* a, const void* b)
{
    const char* key = (const char*)a;
    const char* element = (const char*)b;

    if (*key < *element) {
        return -1;  // Key is less than element
    }
    else if (*key > *element) {
        return 1;   // Key is greater than element
    }
    else {
        return 0;   // Key is equal to element
    }
}

int compare_float(const void* a, const void* b)
{
    const float* key = (const float*)a;
    const float* element = (const float*)b;
    float error = 0.001;

    if(*key < *element + error && *key > *element - error)
    {
        return 0;
    }
    else if (*key < *element + error) {
        return -1;  // Key is less than element
    }
    else{
        return 1;   // Key is greater than element
    }
}

int main()
{
    // Integer array
    int int_arr[] = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };
    int int_size = sizeof(int_arr) / sizeof(int);
    int int_key = 23;

    int* int_result = bsearch(&int_key, int_arr, int_size, sizeof(int), compare_int);

    if (int_result != NULL) {
        printf("Integer Key found at index: %ld\n", int_result - int_arr);
    }
    else {
        printf("Integer Key not found\n");
    }

    // Character array
    char char_arr[] = { 'a', 'c', 'e', 'g', 'i', 'k' };
    int char_size = sizeof(char_arr) / sizeof(char);
    char char_key = 'g';

    char* char_result = bsearch(&char_key, char_arr, char_size, sizeof(char), compare_char);

    if (char_result != NULL) {
        printf("Character Key found at index: %ld\n", char_result - char_arr);
    }
    else {
        printf("Character Key not found\n");
    }

    // Float array
    float float_arr[] = { 1.2, 3.4, 5.600000001, 7.8, 9.0 };
    int float_size = sizeof(float_arr) / sizeof(float);
    float float_key = 5.6;

    float* float_result = bsearch(&float_key, float_arr, float_size, sizeof(float), compare_float);

    if (float_result != NULL) {
        printf("Float Key found at index: %ld\n", float_result - float_arr);
    }
    else {
        printf("Float Key not found\n");
    }

    return 0;
}
