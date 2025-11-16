'''
    Author : Do Quang Vinh
    Vietnam National University - Hanoi
    Created : 18:17:21 - 16/11/2025

'''

from __future__ import annotations
from math import gcd, lcm
import sys

fi = open("test.inp", "r", encoding = "utf-8")
fo = open("test.out", "w", encoding = "utf-8")
sys.stdin = fi
sys.stdout = fo

sys.set_int_max_str_digits(0)

N = int(1e5 + 5)
MOD = int(1e9 + 7)

class Fraction:
    def __init__(self, numerator: int = 0, denominator: int = 1):
        self.numerator = numerator
        self.denominator = denominator
        
    def __str__(self):
        res = ""
        if self.numerator * self.denominator < 0: res += "-"
        res += f"{abs(self.numerator)}/{abs(self.denominator)}"
        return res
    
    def simplest(self) -> Fraction:
        k = gcd(self.numerator, self.denominator)
        self.numerator //= k
        self.denominator //= k
        return self
        
    def __add__(self, other: Fraction):
        res = Fraction(numerator=self.numerator * other.denominator + other.numerator * self.denominator, denominator=self.denominator * other.denominator)
        return res.simplest()
    
    def __sub__(self, other: Fraction):
        res = Fraction(numerator=self.numerator * other.denominator - other.numerator * self.denominator, denominator=self.denominator * other.denominator)
        return res.simplest()
    
    def __mul__(self, other: Fraction):
        res = Fraction(numerator=self.numerator * other.numerator, denominator=self.denominator * other.denominator)
        return res.simplest()
    
    def __truediv__(self, other: Fraction):
        inverse = Fraction(numerator=other.denominator, denominator=other.numerator)
        return self * inverse

n = int(input())
res = Fraction()
for _ in range (n):
    sign, s = map(str, input().split())
    for i in range (len(s)):
        if s[i] == '/':
            f = Fraction(numerator=int(s[:i]), denominator=int(s[i + 1:]))
            break
    if sign == '+': res = res + f
    elif sign == '-': res = res - f
    elif sign == '*': res = res * f
    else: res = res / f
print(res)

# https://oj.vnoi.info/problem/fc138_fraction