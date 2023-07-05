#!/usr/bin/python3
'''making_change'''


def makeChange(coins, total):
    '''Change comes from within'''
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    x = 0
    y = 0
    z = 0
    while x < total:
        x += coins[y]
        z += 1
        if x + coins[y] > total:
            y += 1
    f = x - total
    if f != 0:
        return -1
    return z
