/******************************************************************************
 * Copyright (C) 2026 by Maksym Kolontaievskyi
 *
 * Redistribution or use of this software in source or binary forms
 * is permitted as long as the files maintain this copyright. Users are not
 * permitted to modify this. Maksym Kolontaievskyi is not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief Very basic data manipulation
 *
 * This source file provides very basic data manipulation
 * functions for converting data between standard integer
 * type and ASCII string.
 *
 * @author Maksym Kolontaievskyi
 * @date October 22 2026
 *
 */

#include "data.h"

#ifndef MAX_BASE_10_LENGTH
#define MAX_BASE_10_LENGTH 11 // for -4_294_967_296 (0xFFFF_FFFF)
#endif

#ifndef SIGN_BIT
#define SIGN_BIT 31
#endif

#ifndef ASCII_NUMBER_PREFIX
#define ASCII_NUMBER_PREFIX 0x30

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  uint8_t converted_length = 0;

  if (base == BASE_2) {
    // add digit at position 2^31 to the string
    if ((data & (1 << SIGN_BIT)) != 0) {
      *ptr = ASCII_NUMBER_PREFIX + (uint8_t) 1;
    }

    else {
      *ptr = ASCII_NUMBER_PREFIX + (uint8_t) 0;
    }
    converted_length++;

    int32_t next_bit = SIGN_BIT - 1;

    // add digits between 2^30 and 2^1
    while (next_bit > 0) {
      uint8_t converted_value = (uint8_t) (((1 << next_bit) & data) >> next_bit);
      *(ptr + converted_length) = ASCII_NUMBER_PREFIX + converted_value;
      converted_length++;
      next_bit--;
    }

    // add digit at position 2^0 to the string
    *(ptr + converted_length) = ASCII_NUMBER_PREFIX + (uint8_t) (1 & data);
    converted_length++;
  }

  else if (base == BASE_10) {

  }

  else if (base == BASE_16) {
    int32_t next_nibble = 28;

    // add digits between 16^7 and 16^1 to the string
    while (next_nibble > 0) {
      uint8_t converted_value = (uint8_t) ((((0xF << next_nibble) & data) >> next_nibble) & 0xF);
      if (converted_value < 10) {
        *(ptr + converted_length) = ASCII_NUMBER_PREFIX + converted_value;
      }
      else {
        *(ptr + converted_length) = ASCII_LETTER_PREFIX + (converted_value - 10);
      }
      converted_length++;
      next_nibble -= 4;
    }

    // add digit at position 16^0 to the string
    uint8_t converted_value = (uint8_t) (0xF & data);
    if (converted_value < 10) {
      *(ptr + converted_length = ASCII_NUMBER_PREFIX + converted_value;
    }
    else {
      *(ptr + converted) = ASCII_LETTER_PREFIX + (converted_value - 10);
    }
    converted_length++;
  }

  *(ptr + converted_length) = (uint8_t) '\0';
  return converted_length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
  int32_t result = 0;
  
  return result;
}
