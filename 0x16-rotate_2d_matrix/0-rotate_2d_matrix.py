#!/usr/bin/python3
''' Rotate 2D Matrix'''


def rotate_2d_matrix(matrix):
    '''Given an n x n 2D matrix, rotate it 90 degrees clockwise'''
    N = len(matrix[0])
    for x in range(N // 2):
        for y in range(x, N - x - 1):
            tmp = matrix[x][y]
            matrix[x][y] = matrix[N - 1 - y][x]
            matrix[N - 1 - y][x] = matrix[N - 1 - x][N - 1 - y]
            matrix[N - 1 - x][N - 1 - y] = matrix[y][N - 1 - x]
            matrix[y][N - 1 - x] = tmp
