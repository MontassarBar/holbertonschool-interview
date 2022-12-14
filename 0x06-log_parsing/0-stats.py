#!/usr/bin/python3
'''script that reads stdin line by line and computes metrics'''
import sys


lines = 0
file_size = 0
dict = {"200": 0, "301": 0, "400": 0, "401": 0,
        "403": 0, "404": 0, "405": 0, "500": 0}
try:
    for line in sys.stdin:
        splited_line = line.split(" ")
        if len(splited_line) == 9 and splited_line[
            4] == "\"GET" and splited_line[
                5] == "/projects/260" and splited_line[6] == "HTTP/1.1\"":
            lines += 1
            file_size += int(splited_line[8])
            if splited_line[7].isdigit():
                for key in dict.keys():
                    if key == splited_line[7]:
                        dict[key] += 1
            if lines == 10:
                lines = 0
                print("File size:", file_size)
                for key, value in sorted(dict.items()):
                    if value != 0:
                        print(key + ": " + str(value))
except Exception:
    pass
finally:
    print("File size:", file_size)
    for key, value in sorted(dict.items()):
        if value != 0:
            print(key + ": " + str(value))
