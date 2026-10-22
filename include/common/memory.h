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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */

#include <stddef.h>
#include <stdint.h>

#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves bytes from source to destination
 *
 * Given two byte pointers (one source and one destination) and
 * a length of bytes to move, this function moves bytes from source location
 * to the destination. Source and destination should have equal lengths.
 *
 * @param src Pointer to source array of bytes
 * @param dst Pointer to destination array of bytes
 * @param length A length of bytes to move from source to destination
 *
 * @return dst Pointer to destination array of bytes
 */


/*
 * Added functions include my_memmove, my_memcopy,
 * my_memset, my_memzero, my_reverse, reserve_words,
 * free_words.
 *
 * @author Maskym Kolontaievskyi
 * @date October 22 2026
 *
 */


uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies bytes from source to destination
 *
 * Given two byte pointers (one source and one destination) and
 * a length of bytes to copy, this function copies bytes from source location
 * to the destination. Source and destination should have equal lengths.
 *
 * @param src Pointer to source array of bytes
 * @param dst Pointer to destination array of bytes
 * @param length A length of bytes to copy from source to destination
 *
 * @return dst Pointer to destination array of bytes
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets all locations of source memory to a given value
 *
 * Given a pointer to source memory, a length in bytes and a value to set
 * all locations of that memory, this function sets all location to the
 * specified value.
 *
 * @param src Pointer to source memory
 * @param length A length in bytes of source memory
 * @param value Value to set all locations in source
 *
 * @return src Pointer to source memory
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets all locations of source memory to a zero values
 *
 * Given a pointer to source memory, and length in bytes of that memory,
 * this function sets all location to zero value.
 *
 * @param src Pointer to source memory
 * @param length A length in bytes of source memory
 *
 * @return src Pointer to source memory
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverse the order of all of the bytes
 *
 * Given a pointer to source memory, a length in bytes of that memory,
 * this function reverses the order of all of the bytes inside source memory.
 *
 * @param src Pointer to source memory
 * @param length A length in bytes of source memory
 *
 * @return src Pointer to source memory
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Reserves the block of memory
 *
 * Given a number of words to allocate in dynamic memory,
 * this function tries to reserve the block of memory.
 * Returns Null Pointer otherwise.
 *
 * @param length Number of words to allocate in dynamic memory
 *
 * @return Pointer to memory if successful or Null Pointer if not.
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Frees dynamic memory allocation.
 *
 * Given a pointer of source memory dynamically allocated in memory,
 * this function frees memory allocated to pointer.
 *
 * @param src Pointer to source memory allocation
 *
 * @return None.
 */
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
