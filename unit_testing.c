#include <stdio.h>

/**
 * @file unit_offset_vector.c
 * @brief Demonstration of a unit-offset vector in C.
 *
 * A unit-offset vector is a technique to utilize a specific range of indices
 * within an array, considering the zero-origin behavior of C. This is particularly
 * useful when working with integer values and you want to use a range like a[1..n].
 *
 * @author Mk-0-wan(https://github.com/Mk-0-wan/Mk-0-wan)
 */

float a[4], *bb;

/**
 * @brief Adjusts the base address of the array to create a unit-offset vector.
 *
 * To make use of all indices in the given range, e.g., a[1..4], adjust the base
 * address of the array using the expression (array - 1). This allows easy access
 * to the desired range without the need to manually adjust indices.
 *
 * @param array Pointer to the array.
 * @return Pointer to the adjusted base address, creating a unit-offset vector.
 */
float* create_unit_offset_vector(float* array) 
{
    return array - 1;
}

int main(void)
{
    bb = create_unit_offset_vector(a);

    /* Now bb contains indices from bb[1..4] */
    return 0;
}
