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
 * @file stats.c
 * @brief C program that does statistics analysis on data set.
 *
 * This program prints mean, median, maximum and minimum values
 * of a given array (with a given length) by first sorting this array,
 * then getting mean, median, maximum and minimum from sorted data set.
 * Program also prints sorted array before printing result of satistical
 * analysis.
 *
 * NOTE: For time optimization reasons the sorting function will replace
 * original array with sorted version instead of working with a copy.
 *
 * @author Maksym Kolontaievskyi
 * @date 12.10.2026
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  printf("Sorted array:");
  sort_array(test, SIZE);
  print_array(test, SIZE);
  printf("\n\nStatistics overview:");
  print_statistics(test, SIZE);
  return 0;
}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char *array, const unsigned int LENGTH) {
  char* format_string = "\n\tMinimum: %d\n\tMaximum: %d\n\tMedian: %d\n\tMean: %d\n";

  printf(
    format_string,
    find_minimum(array, LENGTH),
    find_maximum(array, LENGTH),
    find_median(array, LENGTH),
    find_mean(array, LENGTH)
  );
}

void print_array(const unsigned char *array, const unsigned int LENGTH) {
#ifdef VERBOSE
  unsigned int N = LENGTH;

  if (LENGTH % 7 == 0) N = 7;

  else if (LENGTH % 5 == 0) N = 5;

  else if (LENGTH % 3 == 0) N = 3;

  else if (LENGTH % 2 == 0) N = 2;

  for (unsigned int i = 0; i < LENGTH; i++) {
    // use N as separator for rows
    if (i % N == 0) {
      printf("\n");
    }
    printf("%d\t", array[i]);
  }
#endif
}

unsigned char find_median(unsigned char *array, const unsigned int LENGTH) {
  sort_array(array, LENGTH);

  unsigned int index_of_middle = LENGTH / 2;

  if (LENGTH % 2 == 1) {
    return array[index_of_middle];
  }

  return (array[index_of_middle] + array[index_of_middle - 1]) / 2.0;
}

unsigned short find_mean(const unsigned char *array, const unsigned int LENGTH) {
  unsigned short sum = 0;

  for (unsigned int i = 0; i < LENGTH; i++) {
    sum += array[i];
  }

  return sum / (float) LENGTH;
}

unsigned char find_maximum(const unsigned char *array, const unsigned int LENGTH) {
  unsigned char maximum = array[0];

  for (unsigned int i = 0; i < LENGTH; i++) {
    if (array[i] > maximum) maximum = array[i];
  }

  return maximum;
}

unsigned char find_minimum(const unsigned char *array, const unsigned int LENGTH) {
  unsigned char minimum = array[LENGTH - 1];

  for (unsigned int i = 0; i < LENGTH; i++) {
    if (array[i] < minimum) minimum = array[i];
  }

  return minimum;
}

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

