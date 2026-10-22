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
 * @file main.c
 * @brief Entry point for a program
 *
 * This source file provides entry point for a program
 * that contains solutions for the final assignment
 * of the Introduction to Embedded Systems Software and
 * Development Environments as well as provided libraries
 * and functions by the by Alex Fosdick from University of Colorado
 * to create a foundation and test the solutions provided.
 *
 * @author Maksym Kolontaievskyi
 * @date October 22 2026
 *
 */


#include "course1.h"

int main() {
#ifdef COURSE1
  course1();
#endif
  return 0;
}

