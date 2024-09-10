import sys

sys.set_int_max_str_digits(0)

n, k = map(int, input().split())
dp = [[0 for i in range (2)] for i in range (n + 1)]

'''

dp[i][0 / 1] : số lượng số có i chữ số, kết thúc / không kết thúc tại 0
dp[i][0] -= dp[i - 1][0] 
dp[i][j] += dp[i - 1][j]

'''

dp[1][0] = 1
dp[1][1] = k - 1

def Accept() :
    for i in range (2, n + 1) :
        s = dp[i - 1][0] + dp[i - 1][1]
        for digit in range (k) :
            state = 1
            if digit == 0 : state = 0
            if i == 2 or digit == 0 : dp[i][state] -= dp[i - 1][0]
            dp[i][state] += s
    
Accept()
print(dp[n][0] + dp[n][1])

# https://oj.vnoi.info/problem/digit