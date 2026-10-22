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
 * @file data.h
 * @brief Very basic data manipulation
 *
 * This header file provides very basic data manipulation
 * functions for converting data between standard integer
 * type and ASCII string.
 *
 * @author Maksym Kolontaievskyi
 * @date October 22 2026
 *
 */

#include <stddef.h>
#include <stdint.h>

#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Converts data from standard integer type into ASCII string.
 *
 * Given a number to be converted in form of a single 32-bit signed integer,
 * destination pointer to block in memory where converted string
 * will be stored and the number that identifies one of the supported
 * bases (2 to 16) that you wish to convert to, this function applies
 * conversion using pointer arithmetic and returns the length of
 * the converted data (including a negative sign).
 *
 * @param data The number you wish to convert
 * @param ptr The pointer to converted ASCII string
 * @param base The base you wish to convert to (bases 2 to 16)
 *
 * @return Length of the converted data (including a negative sign).
 */

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts data from ASCII string into standard integer type.
 *
 * Given a destination pointer to block in memory where ASCII string
 * is placed, a number of digits in a given character set (ASCII string),
 * and the number that identifies one of the supported bases (2 to 16)
 * that you wish to convert to, this function applies conversion using
 * pointer arithmetic and returns the converted 32-bit signed integer.
 *
 * @param ptr The pointer to character string (ASCII) to convert
 * @param digits The number of digits in a given character set
 * @param base The base you wish to convert to (bases 2 to 16)
 *
 * @return Converted 32-bit signed integer value.
 */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif

