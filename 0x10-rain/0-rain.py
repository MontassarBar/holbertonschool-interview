#!/usr/bin/python3

def rain(walls):
    x = len(walls) - 1
    y = 0
    water = 0
    if walls[-1] == 0:
        x = x - 1
    if walls[0] == 0:
        y = y + 1
    while(y < x):
        if (y + 1) <= x:
            z = y + 1
        count = 0
        while(walls[z] == 0):
            z += 1
            count += 1
        if walls[z] < walls[y]:
            water += count * walls[z]
        else:
            water += count * walls[y]
        if z != x - 1:
            y += count + 1
    return water
    