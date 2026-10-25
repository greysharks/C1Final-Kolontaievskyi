## Copyright (C) 2026 by Maksym Kolontaievskyi 
## Redistribution, modification or use of this software in source or binary forms is permitted as long as the files maintain this copyright. Maksym Kolontaievskyi is not liable for any misuse of this material. 

The purpose of this project is to practice implementing algorithms
for embedded systems such as converting data in form of 32-bit integer
values to ASCII strings and vice versa.

---

The conversion happens based on the base argument provided (supported 
bases are base-2, base-10 and base-16). The algorithm is optimized for
each base separately: the fasted conversions happen for base-2 numbers,
the slowest happen for base-10 numbers.

---

This repository also contains functions for statistical analysis made in module 1
as well as functions for some memory manipulation (moving, copying, setting with value
or setting with zeros, reserving and freeing).
