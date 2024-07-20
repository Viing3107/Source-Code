'''
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 11:25:29 - 20/07/2024

'''

import sys

task = "test"

fi = open(task + ".inp", "r", encoding = "utf-8")
fo = open(task + ".out", "w", encoding = "utf-8")
sys.stdin = fi
sys.stdout = fo

N = int(1e5 + 5)

n, m = map(int, input().split())
a = [0] * N
b = [0] * N
result = 0

for i in range (1, n + 1) : a[i], b[i] = map(int, input().split())

def f(x) :
    res = 0
    for i in range (1, n + 1) :
        res += (x // (b[i] + 1)) * a[i] * b[i] + (x % (b[i] + 1)) * a[i]
    return res

l = 0
r = int(1e18)

while (r - l >= 0) :
    mid = l + r >> 1
    if f(mid) >= m :
        result = mid
        r = mid - 1
    else : l = mid + 1
    
print(result)
        
    
# https://oj.vnoi.info/problem/icpc21_mb_j