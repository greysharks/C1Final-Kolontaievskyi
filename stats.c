/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */

#include <math.h>
#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);
  sort_array(test, SIZE);
  print_array(test, SIZE);
}

/* Add other Implementation File Code Here */

void print_statistics(const unsigned char *array, const unsigned int LENGTH) {}

void print_array(const unsigned char *array, const unsigned int LENGTH) {
  // suppose the array's length is NxN,
  // then N is both number of rows and number of columns
  const unsigned int N = (unsigned int) sqrt((float) LENGTH);

  for (unsigned int i = 0; i < LENGTH; i++) {
    // use N as separator for rows
    if (i % N == 0) {
      printf("\n");
    }
    printf("%d\t", array[i]);
  }

  // start new line before returning to console
  printf("\n");
}

unsigned char find_median(const unsigned char *array, const unsigned int LENGTH) {}
unsigned char find_mean(const unsigned char *array, const unsigned int LENGTH) {}
unsigned char find_maximum(const unsigned char *array, const unsigned int LENGTH) {}
unsigned char find_minimum(const unsigned char *array, const unsigned int LENGTH) {}

void sort_array(unsigned char *array, const unsigned int LENGTH) {
  void quick_sort(unsigned int start, unsigned int end) {
    if (start == end) {
      return;
    }

    unsigned int pivot = end;
    unsigned int index = start;

    while (pivot - 1 != index) {
      if (array[index] < array[pivot]) {
        // swap array[pivot - 1] and array[pivot]
        array[pivot - 1] = array[pivot - 1] ^ array[pivot];
        array[pivot] = array[pivot - 1] ^ array[pivot];
        array[pivot - 1] = array[pivot - 1] ^ array[pivot];

        // swap array[pivot] and array[index]
        array[pivot] = array[pivot] ^ array[index];
        array[index] = array[pivot] ^ array[index];
        array[pivot] = array[pivot] ^ array[index];
      }

      else {
        index++;
      }
    }

    if (array[index] < array[pivot]) {
      // swap array[index] and array[pivot]
      array[index] = array[index] ^ array[pivot];
      array[pivot] = array[index] ^ array[pivot];
      array[index] = array[index] ^ array[pivot];
    }

    index++;

    quick_sort(start, index - 1);
    quick_sort(pivot, end);
  }

  quick_sort(0, LENGTH - 1);
}

