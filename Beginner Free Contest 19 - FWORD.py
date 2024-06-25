'''
  Author : Do Quang Vinh
  Kim Son A High School - Ninh Binh
  Created : 17:33:46 - 25/06/2024

'''
import sys
fi = open("test.inp", "r", encoding = "utf-8")
fo = open("test.out", "w", encoding = "utf-8")
sys.stdin = fi
sys.stdout = fo

from bisect import bisect_left

n, m, k, x = map(int, input().split())
s = str(input())

a = [""]

for i in range (1, m + 1) :
    t = str(input())
    t = sorted(t)
    tmp = [""]
    for j in range (len(t)) : tmp.append(t[j])
    a.append(tmp)
    
cnt = [[0] * (k + 1) for i in range (m + 1)]

for i in range (m, 0, -1) :
    for j in range (1, k + 1) : cnt[i][j] = j * pow(k, m - i)
    
result = [""]

for i in range (1, m + 1) :
    if (x <= 0) : break
    idx = bisect_left(cnt[i], x)
    if (idx <= k) : 
        result.append(a[i][idx])
        x -= cnt[i][idx - 1]
        
d = 0
for x in s :
    if (x == '#') :
        d += 1
        x = result[d]
    print(x, end = "")

fi.close()
fo.close()

# https://oj.vnoi.info/problem/fcb019_fword