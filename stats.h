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
 * @file stats.h
 * @brief Header file for statistics analysis functions.
 *
 * First part of functions inside this file is meant for printing
 * information:
 *   - print_array() that prints given array in form of NxN matrix
 *   - print_statistcs() that prints statistics of the sorted data set.
 *
 * Second part of functions inside this file is meant for calculating
 * statistics values on a sorted array:
 *   - find_maximum() finds maximum value inside data set
 *   - find_minimum() finds minimum value inside data set
 *   - find_mean() calculates mean value for the data set
 *   - find_median() calculates median value for the data set.
 *
 * Lastly, there is sort_array() function that is reponsible for sorting
 * data set from largest to smallest value.
 *
 * @author Maksym Kolontaievskyi
 * @date 12.10.2026
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

void print_statistics(unsigned char *array, const unsigned int LENGTH);

/*
 * @brief Prints the statistics of an array.
 *
 * Given an array of data and its length, this
 * function finds and prints its statistics
 * including minimum, maximum, mean and median.
 *
 * @param array An array of data.
 * @param LENGTH Length of a given array.
 *
 * @return Doesn't return any value.
 */

void print_array(const unsigned char *array, const unsigned int LENGTH);

/*
 * @brief Prints the array to the screen.
 *
 * Given an array of data and a length,
 * this function prints the array to the
 * screen in form of NxN matrix as close
 * as possible.
 *
 * @param array An array of data.
 * @param LENGTH Length of a given array.
 *
 * @return Doesn't return any value.
 */

unsigned char find_median(const unsigned char *array, const unsigned int LENGTH);

/*
 * @brief Finds the median value.
 *
 * Given a sorted array of data and its length,
 * returns the median value (when data set is
 * even, the median value is rounded to the
 * nearest integer).
 *
 * @param array An array of data.
 * @param LENGTH Length of a given array.
 *
 * @return calculated median value.
 */

unsigned short find_mean(const unsigned char *array, const unsigned int LENGTH);

/*
 * @brief Finds the mean value.
 *
 * Given a sorted array of data and its length,
 * returns the mean value.
 *
 * @param array An array of data.
 * @param LENGTH Length of a given array.
 *
 * @return calculated mean value.
 */

unsigned char find_maximum(const unsigned char *array, const unsigned int LENGTH);

/*
 * @brief Finds the maximum value.
 *
 * Given a sorted array of data and its length,
 * returns the maximum value.
 *
 * @param array An array of data.
 * @param LENGTH Length of a given array.
 *
 * @return calculated maximum value.
 */

unsigned char find_minimum(const unsigned char *array, const unsigned int LENGTH);


/*
 * @brief Finds the minimum value.
 *
 * Given a sorted array of data and its length,
 * returns the minimum value.
 *
 * @param array An array of data.
 * @param LENGTH Length of a given array.
 *
 * @return calculated minimum value.
 */

void sort_array(unsigned char *array, const unsigned int LENGTH);

/*
 * @brief Sorts the array from largest to smallest.
 *
 * Given an array of data and a length,
 * this function sorts the array using
 * a quick sort algorithm where the first
 * element will become a largest value
 * inside the array and the last element
 * will become the smallest value.
 *
 * @param array An array of data.
 * @param LENGTH Length of a given array.
 *
 * @return Doesn't return any value.
 */


#endif /* __STATS_H__ */
