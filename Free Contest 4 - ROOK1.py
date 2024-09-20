import sys, math

sys.set_int_max_str_digits(0)

MOD = 1000001

t = int(input())

for _ in range (t):
    n, m, k = map(int, input().split())
    print(math.comb(n, k) * math.perm(m, k) % MOD)

# https://oj.vnoi.info/problem/fc004_rook1