'''
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 11:33:15 - 20/07/2024

'''

import sys

task = "test"

fi = open(task + ".inp", "r", encoding = "utf-8")
fo = open(task + ".out", "w", encoding = "utf-8")
sys.stdin = fi
sys.stdout = fo

def singleTest(a, n, x) :
    a.sort()
    for i in range (1, n + 1) :
        if (x >= a[i]) : x *= (i + 1) / i
        else :
            print(i - 1)
            return
    print(n)

t = int(input())
for _ in range (t) :
    n, x = map(int, input().split())
    a = [0] + list(map(int, input().split()))
    singleTest(a, n, x)

# https://oj.vnoi.info/problem/vnoicup24_r2_a