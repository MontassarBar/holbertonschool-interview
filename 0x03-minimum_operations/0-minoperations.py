#!/usr/bin/python3

'''calculates the fewest number of operations needed to result
 in exactly n H characters in the file.'''

from math import sqrt


def minOperations(n):
    x = sqrt(n)
    if x ** 2 == n:
        return int(x * 2)
    elif n % 2 == 0:
        return int(n / 2 + 1)
