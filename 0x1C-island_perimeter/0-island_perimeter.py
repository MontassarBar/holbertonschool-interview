#!/usr/bin/python3
'''Island Perimeter'''


def island_perimeter(grid):
    '''function that returns the perimeter of the island described in grid'''
    p = 0
    for x in range(len(grid)):
        for y in range(len(grid[x])):
            if grid[x][y] == 1:
                if grid[x][y + 1] == 0:
                    p += 1
                if grid[x][y - 1] == 0:
                    p += 1
                if grid[x + 1][y] == 0:
                    p += 1
                if grid[x - 1][y] == 0:
                    p += 1
    return p
