#!/usr/bin/python3
'''Island Perimeter'''


def island_perimeter(grid):
    '''function that returns the perimeter of the island described in grid'''
    if not grid:
        return 0
    p = 0
    for x in range(1, len(grid) - 1):
        for y in range(1, len(grid[x]) - 1):
            if grid[x][y] == 1:
                if grid[x][y + 1] == 0 and x:
                    p += 1
                if grid[x][y - 1] == 0:
                    p += 1
                if grid[x + 1][y] == 0:
                    p += 1
                if grid[x - 1][y] == 0:
                    p += 1
    return p
