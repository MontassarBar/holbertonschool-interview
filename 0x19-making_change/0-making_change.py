#!/usr/bin/python3
'''making_change'''


def makeChange(coins, total):
    '''Change comes from within'''
    if total <= 0:
        return 0
    coins.sort()
    reversed = coins[::-1]
    x = 0
    for coin in reversed:
        x += total // coin
        total = total % coin
    if total != 0:
        return -1
    return x
