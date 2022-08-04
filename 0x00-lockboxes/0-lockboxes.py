#!/usr/bin/python3
'''Lockboxes'''


def canUnlockAll(boxes):
    n = len(boxes)
    i = 0
    x = 1
    while (x < n):
        g = 0
        y = 0
        while (y < n):
            z = 0
            l = len(boxes[y])
            if l == 0:
                y += 1
            while (z < l):
                if x == boxes[y][z] and y != x:
                    i += 1
                    x += 1
                    g = 1
                    break
                else:
                    z += 1
            if g == 1:
                break
            else:
                y += 1
        if g != 1:
            x += 1
    if i == n - 1:
        return True
    else:
        return False
