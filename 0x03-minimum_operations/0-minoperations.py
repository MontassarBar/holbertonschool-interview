#!/usr/bin/python3

'''calculates the fewest number of operations needed to result
 in exactly n H characters in the file.'''


def minOperations(n):
    x = 0
    i = 2
    while (i <= n):
        while n % i == 0:
            x += i
            n = n / i
        i += 1
    return x
