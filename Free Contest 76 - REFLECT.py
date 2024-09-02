X0 = 0
Y0 = 0

n = int(input())
for i in range (1, n + 1) :
    x, y = map(int, input().split())
    X0 += x
    Y0 += y    
a, b, c = map(float, input().split())

X0 /= n
Y0 /= n

print("%.4f" % X0, "%.4f" % Y0)

X = (b ** 2 * X0 - a * b * Y0 - 2 * a * c - a ** 2 * X0 - a * b * Y0) / (a ** 2 + b ** 2)
Y = (-2 * c - a * X0 - b * Y0 - a * X) / b

print("%.4f" % X, "%.4f" % Y)

# https://oj.vnoi.info/problem/fc076_reflect