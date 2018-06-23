"""
using ctypes https://docs.python.jp/3/library/ctypes.html
"""

from ctypes import cdll, c_int, c_double

import sys
print(sys.version)

mylib = cdll.LoadLibrary("libmypi.so")

mylib.calc_pi.argtypes = [c_int]
mylib.calc_pi.restype = c_double

pi = mylib.calc_pi(c_int(1000))
print(pi)
