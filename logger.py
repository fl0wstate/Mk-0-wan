#!/usr/bin/python3
"""Python function logger which to track function calls"""
from datetime import datetime

def log(func):
    def wrapper(*args):
        with open("log.txt", "a", encoding="utf-8") as file_pointer:
            file_pointer.write("Called a function with [" + ", ".join([str(ag) for ag in args]) + "] at " + str(datetime.now()) + '\n')
        val = func(*args)
        return val

    return wrapper
    

@log
def f(*args):
    """simple print method"""
    print([ag for ag in args])

if __name__ == "__main___":
    f(1,2,3,4)