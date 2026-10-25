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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"
#include <stdlib.h>

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

/*
 * Added functions include my_memmove, my_memcopy,
 * my_memset, my_memzero, my_reverse, reserve_words,
 * free_words.
 *
 * @author Maskym Kolontaievskyi
 * @date October 22 2026
 *
 */

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {

  // move data from start if destination has lower or equal address
  if (dst <= src) {
    for (size_t i = 0; i < length; i++) {
      *(dst + i) = *(src + i);
    }
  }

  // move data from end if destination has higher address
  else {
    for (size_t i = length; i > 0; i--) {
      *(dst + i - 1) = *(src + i - 1);
    }
  }

  return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {

  // copy data with loss when source overlaps with destination
  for (size_t i = 0; i < length; i++) {
    *(dst + i) = *(src + i);
  }

  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {

  // set all memory locations to same value
  for (size_t i = 0; i < length; i++) {
    *(src + i) = value;
  }

  return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {

  // set all memory locations to zeros
  for (size_t i = 0; i < length; i++) {
    *(src + i) = 0;
  }

  return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length) {

  // swap all values that are symmetrical towards center
  for (size_t i = 0; i < length / 2; i++) {

    // store combination of values (XOR) in first memory location
    *(src + i) ^= *(src + (length - 1 - i));

    // get first value and store as second
    *(src + (length - 1 - i)) ^= *(src + i);

    // get second value and store as first
    *(src + i) ^= *(src + (length - 1 - i));
  }

  return src;
}

int32_t * reserve_words(size_t length) {
  return (int32_t *) malloc(sizeof (int32_t) * length);
}

void free_words(int32_t * src) {
  if (src != NULL) {
    free(src);
  }
}
