#!/usr/bin/python3
'''calculate how many square units of water will be retained after it rains'''


def rain(walls):
    '''rain'''
    if len(walls) == 0:
        return 0
    x = len(walls) - 1
    y = 0
    water = 0
    for m in range(x, 0, -1):
        if walls[m] == 0:
            x -= 1
        else:
            break
    if walls[y] == 0:
        while walls[y] == 0:
            y += 1
    while y < x:
        if (y + 1) <= x:
            z = y + 1
        count = 0
        while walls[z] == 0:
            z += 1
            count += 1
        if walls[z] < walls[y]:
            water += count * walls[z]
        else:
            water += count * walls[y]
        if z != x - 1:
            y += count + 1
    return water
