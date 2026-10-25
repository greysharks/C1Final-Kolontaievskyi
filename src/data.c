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

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  uint8_t converted_length = 0;
  int32_t start_adding_to_string = false;

  if (base == BASE_2) {

    // start from highest bit of a number (2^31)
    int32_t next_bit = SIGN_BIT;

    // add digits between 2^31 and 2^0 to the string
    while (next_bit >= 0) {

      // allign bit with data based on next_bit position
      uint8_t bit = (1 << next_bit) & data;

      // scale down the number to get the actual value
      uint8_t converted_value = (uint8_t) ((bit >> next_bit) & 1);

      // make sure not to include all leading zeros to ASCII string
      if (converted_value != 0) {
        start_adding_to_string = true;
      }


      if (start_adding_to_string == true) {

        // finally, shift the converted value based on ASCII table
        *(ptr + converted_length) = ASCII_NUMBER_PREFIX + converted_value;
        converted_length++;
      }

      next_bit--;
    }
  }

  else if (base == BASE_16) {

    // start from highest nibble
    int32_t next_nibble = 28; // starting position of 0xF0000000

    // add digits between 16^7 and 16^0 to the string
    while (next_nibble >= 0) {

      // allign nibble with data based on next_nibble position
      uint8_t nibble = (0xF << next_nibble) & data;

      // scale down the number to get the actual value
      uint8_t converted_value = (uint8_t) ((nibble >> next_nibble) & 0xF);

      // make sure not to include all leading zeros to ASCII string
      if (converted_value != 0) {
        start_adding_to_string = true;
      }

      if (start_adding_to_string == true) {

        // check if should be ASCII number or ASCII letter
        if (converted_value < 0xA) { // A = 10 in hex
          *(ptr + converted_length) = ASCII_NUMBER_PREFIX + converted_value;
        }
        else {
          // letter A in ASCII is at index 0 starting from 0x41 (not at index 10)
          converted_value -= 0xA;
          *(ptr + converted_length) = ASCII_LETTER_PREFIX + converted_value;
        }
        converted_length++;
      }

      // each hexadecimal value is half a byte or 4 bits
      next_nibble -= 4;
    }
  }

  else if (base == BASE_10) {

    // check if number is negative based on highest bit
    if ((data & (1 << SIGN_BIT)) != 0) { // (1 << SIGN_BIT) = 2^31

      // add minus sign in the beggining of the string
      *ptr = (uint8_t) '-';

      // find the opposite number (additive inverse)
      data = (~data) + 1; // use 2s-complement conversion

      converted_length++;
    }

    // start from 10^10
    long long next_divisor = MAX_DIVISOR;

    // add digits between 10^10 and 10^0 to the string
    while (next_divisor > 1) {

      // get value of 10^next_divisor in data (i.e. from highest to lowest)
      uint8_t converted_value = (uint8_t) ((data % next_divisor - data % (next_divisor / 10)) / (next_divisor / 10));


      // make sure not to include all leading zeros to ASCII string
      if (converted_value != 0) {
        start_adding_to_string = true;
      }


      if (start_adding_to_string == true) {

        // finally, shift the converted value based on ASCII table
        *(ptr + converted_length) = ASCII_NUMBER_PREFIX + converted_value;
        converted_length++;
      }

      next_divisor /= 10;
    }
  }

  // end a string
  *(ptr + converted_length) = (uint8_t) '\0';

  return converted_length;
}

uint32_t pow_uint(uint8_t base, uint8_t power) {
  if (power == 0) { // base^0 = 1
    return 1;
  }

  uint32_t base_to_power = base; // base^1 = base

  // enters loop from base^2
  for (uint8_t j = 1; j < power; j++) {
    base_to_power *= base;
  }

  return base_to_power;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
  int32_t result = 0;

  if (base == BASE_2) {
    for (uint8_t i = 0; i < digits; i++) {

      // value of ASCII character > value of actual number
      uint8_t digit = *(ptr + i) - ASCII_NUMBER_PREFIX;

      // scale the number to corresponding bit position
      result += digit << (digits - 1 - i);
    }
  }

  else if (base == BASE_16) {
    for (uint8_t i = 0; i < digits; i++) {

      // get ASCII character
      uint8_t digit = *(ptr + i);

      // check if it's not a letter
      if (digit < ASCII_LETTER_PREFIX) {
        digit -= ASCII_NUMBER_PREFIX; // digit -= position of '0' in ASCII table
      }

      else {
        digit -= ASCII_LETTER_PREFIX; // digit -= position of 'A' in ASCII table

        // letters start from index 0 after position of 'A' in ASCII table
        digit += 0xA; // e.g. 'B' = 0x42, 'F' = 0x46
      }

      // scale the number to corresponding nibble position
      result += (uint8_t) digit << ((digits - 1 - i) * 4); // 1 nibble = 4 bits
    }
  }

  else if (base == BASE_10) {
    int32_t is_negative = false;

    // minus sign should be first character of the string
    if (*ptr == '-') {
      is_negative = true;
    }

    // if there is no '-' in the beggining, then first digit is at *(ptr)
    uint8_t step = 0;

    if (is_negative == true) {

      // if number is negative, then the first digit will be at *(ptr + 1)
      step++;
    }

    for (uint8_t i = step; i < digits + step; i++) {

      // value of ASCII character > value of actual number
      uint8_t digit = *(ptr + i) - ASCII_NUMBER_PREFIX;

      // scale the number to corresponding power of ten
      result += digit * pow_uint(10, digits + step - 1 - i);
    }

    if (is_negative == true) {

      // if number is negative, then result should be inverted
      result = ~result + 1;
    }
  }

  return result;
}
