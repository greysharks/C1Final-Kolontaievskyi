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
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

void print_statistics(const unsigned char *array, const unsigned int LENGTH);

/*
 * @brief Prints the statistics of an array.
 *
 * Given an array of data and its length, this
 * function sorts the array, then finds and
 * prints its statistics including minimum,
 * maximum, mean and median.
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
 * returns the median value.
 *
 * @param array An array of data.
 * @param LENGTH Length of a given array.
 *
 * @return calculated median value.
 */

unsigned char find_mean(const unsigned char *array, const unsigned int LENGTH);

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
 * a merge sort algorithm where the first
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
