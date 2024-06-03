import sys

fi = open("test.inp", "r", encoding = "utf-8")
fo = open("test.out", "w", encoding = "utf-8")
sys.stdin = fi
sys.stdout = fo

f = [0] * 50
fibo = [0] * 50;

'''
    gọi f[i] là số lượng kí tự 'a' xuất hiện trong xâu
    gọi fibo[i] là độ dài của xâu
'''

f[0] = 1
f[1] = 0
for i in range (2, 46) : f[i] = f[i - 1] + f[i - 2]

fibo[0] = 1
fibo[1] = 1
for i in range (2, 46) : fibo[i] = fibo[i - 1] + fibo[i - 2]

def solve(k, n) :
    if (n < 0) : return 0
    if (n == 0) : return 1
    elif (n == 1) : return 0
    if (fibo[n] == k) : return f[n]
    elif (fibo[n - 2] < k) : return f[n - 2] + solve(k - fibo[n - 2], n - 1)
    else : return solve(k, n - 2)

t = int(input())
for _ in range (1, t + 1) :
    n, k = map(int, input().split())
    print(solve(k, n))

fi.close()
fo.close()

# https://oj.vnoi.info/problem/fc009_fib2

# Nháp và mọi thứ mình để ở đây : https://wbd.ms/share/v2/aHR0cHM6Ly93aGl0ZWJvYXJkLm1pY3Jvc29mdC5jb20vYXBpL3YxLjAvd2hpdGVib2FyZHMvcmVkZWVtLzM4OGNkNjdhOGU3NzQ5OWRhOGM3ZDYxMWI1N2M1YTNiX0JCQTcxNzYyLTEyRTAtNDJFMS1CMzI0LTVCMTMxRjQyNEUzRF8xODc4N2M2Mi1lNTAyLTRkN2UtYmI0NC03ZWMyNDYzNDQ4OTE=