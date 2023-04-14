#!/usr/bin/python3

'''calculates the fewest number of operations needed to result
 in exactly n H characters in the file.'''


def minOperations(n):
    x = 0
    if (n < 2):
        return 0
    for i in range(2, n):
        while n % i == 0:
            x += i
            n = n / i
    return x
