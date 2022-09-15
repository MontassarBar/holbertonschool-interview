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
        if len(splited_line) == 9:
            lines += 1
            s = splited_line[8]
            for key in dict.keys():
                if key == splited_line[7]:
                    dict[key] += 1
            file_size += int(s)
            if lines == 10:
                lines = 0
                print("File size:", file_size)
                for key, value in dict.items():
                    if value != 0:
                        print(key + ": " + str(value))
except Exception:
        pass
finally:
    print("File size:", file_size)
    for key, value in dict.items():
        if value != 0:
            print(key + ": " + str(value))
