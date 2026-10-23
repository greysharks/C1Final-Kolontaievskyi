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


#ifndef BASE_2
#define BASE_2 2
#endif

#ifndef BASE_10
#define BASE_10 10
#endif

#ifndef BASE_16
#define BASE_16 16
#endif

#ifndef MAX_DIVISOR
#define MAX_DIVISOR 10000000000
#endif

#ifndef SIGN_BIT
#define SIGN_BIT 31
#endif

#ifndef ASCII_NUMBER_PREFIX
#define ASCII_NUMBER_PREFIX 0x30
#endif

#ifndef ASCII_LETTER_PREFIX
#define ASCII_LETTER_PREFIX 0x41
#endif

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  uint8_t converted_length = 0;

  if (base == BASE_2) {
    int32_t next_bit = SIGN_BIT;

    // add digits between 2^31 and 2^0
    while (next_bit >= 0) {
      uint8_t converted_value = (uint8_t) ((((1 << next_bit) & data) >> next_bit) & 1);
      *(ptr + converted_length) = ASCII_NUMBER_PREFIX + converted_value;
      converted_length++;
      next_bit--;
    }
  }

  else if (base == BASE_10) {
    if ((data & (1 << SIGN_BIT)) != 0) {
      *ptr = (uint8_t) '-';
      data = (~data) + 1; // use 2s-complement conversion
      converted_length++;
    }

    long long next_divisor = MAX_DIVISOR;

    while (next_divisor > 1) {
      uint8_t converted_value = (uint8_t) ((data % next_divisor - data % (next_divisor / 10)) / (next_divisor / 10));
      *(ptr + converted_length) = ASCII_NUMBER_PREFIX + converted_value;
      converted_length++;
      next_divisor /= 10;
    }
  }

  else if (base == BASE_16) {
    int32_t next_nibble = 28;

    // add digits between 16^7 and 16^1 to the string
    while (next_nibble >= 0) {
      uint8_t converted_value = (uint8_t) ((((0xF << next_nibble) & data) >> next_nibble) & 0xF);
      if (converted_value < 10) { // A = 10
        *(ptr + converted_length) = ASCII_NUMBER_PREFIX + converted_value;
      }
      else {
        *(ptr + converted_length) = ASCII_LETTER_PREFIX + (converted_value - 10);
      }
      converted_length++;
      next_nibble -= 4;
    }
  }

  *(ptr + converted_length) = (uint8_t) '\0';
  return converted_length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
  int32_t result = 0;

  return result;
}
