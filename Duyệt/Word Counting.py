'''
    Author : Do Quang Vinh
    Kim Son A High School - Ninh Binh
    Created : 10:49:33 - 03/07/2024

'''
import sys
fi = open("test.inp", "r", encoding = "utf-8")
fo = open("test.out", "w", encoding = "utf-8")
sys.stdin = fi
sys.stdout = fo

q = int(input())

for i in range (1, q + 1, 1) :
    a = list(map(str, input().split()))
    length = []
    for x in a : length.append(len(x))
    result = present = 0
    for i in range (len(length)) :
        if (length[i] == length[i - 1]) : present += 1
        else : present = 1
        result = max(result, present)
    print(result)

fi.close()
fo.close()

# https://oj.vnoi.info/problem/wordcnt