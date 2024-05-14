import sys

fi = open("test.inp", "r", encoding = "utf-8")
fo = open("test.out", "w", encoding = "utf-8")
sys.stdin = fi
sys.stdout = fo

import math

"""

Xét một xâu độ dài n có dạng S = c1c1c1...c2c2c2...c3c3.....cm, trong đó có n1 kí tự c1, n2 kí tự c2, n3 kí tự c3, ..., nm kí tự cm
=> Số hoán vị không lặp lại của S là : n! / (n1! * n2! * n3! * ... * nm!)
Chứng minh tính đúng đắn của công thức :
    ta có n phần tử thì sẽ có n! cách xếp
    trong đó :
        có n1 phần tử c1, khi hoán vị các phần tử này thì không tạo ra hoán vị mới :
            có n1! cách xếp
        có n2 phần tử c2, khi hoán vị các phần tử này thì không tạo ra hoán vị mới :
            có n2! cách xếp
        có n3 phần tử c3, khi hoán vị các phần tử này thì không tạo ra hoán vị mới :
            có n3! cách xếp
        ...
        có nm phần tử cm, khi hoán vị các phần tử này thì không tạo ra hoán vị mới :
            có nm! cách xếp
    --> Khi loại đi các TH trùng nhau, số hoán vị còn lại sẽ là : n! / (n1! * n2! * n3! * ... * nm!)
    
    Đề hiểu rõ hơn về công thức, có thể tìm hiểu tại : https://vnhoctap.com/hoan-vi-lap/
    
"""
cnt = [0] * 30

s = str(input())
n = len(s)
s = " " + s
ans = 0
t = math.factorial(n)
m = 1

for i in range (1, n + 1) : cnt[ord(s[i]) - 96] += 1
for i in range (1, 27) : m *= math.factorial(cnt[i])
t //= m
while t % 10 == 0:
    ans += 1
    t //= 10
    
print(ans)

fi.close()
fo.close()

# https://oj.vnoi.info/problem/digit0