import sys

name = "test"

fi = open("test.inp", "r", encoding = 'utf-8')
fo = open("test.out", "w", encoding = 'utf-8')
sys.stdin = fi
sys.stdout = fo

res = [0] * 1003
prefixSum = [0] * 1003
res[2] = 1
prefixSum[2] = 1
for i in range (3, 1001) :
    res[i] = prefixSum[i - 1]
    if (i % 2 == 0) : res[i] += 1
    prefixSum[i] = prefixSum[i - 1] + res[i]
for i in int(sys.stdin) : print(res[i])

fi.close()
fo.close()

# https://oj.vnoi.info/problem/m00pair
# kĩ thuật nhập nhiều số khác dòng trong python
