'''
  Author : Do Quang Vinh
  Kim Son A High School - Ninh Binh
  Created : 19:15:56 - 08/06/2024

'''
import sys
fi = open("test.inp", "r", encoding = "utf-8")
fo = open("test.out", "w", encoding = "utf-8")
sys.stdin = fi
sys.stdout = fo

def isDigit(s) :
    for i in s :
        if i == "." or i == "-" : continue
        if i < "0" or i > "9" : return False
    return True

def isAlpha(s) :
    for i in s :
        if (i < "a" or i > "z") and (i < "A" or i > "Z") : return False
    return True

while True :
    a = list(map(str, input().split()))
    if a[0] == "?" : break
    isNumber = False
    isString = False
    for i in a :
        if isDigit(i) : isNumber = True
        elif isAlpha(i) : isString = True
    if isNumber == True and isString == False :
        a = list(map(float, a))
        print("%.6f" % sum(a))
    if isNumber == False and isString == True :
        for i in a : print(i, end = "")
        print()
    if isNumber == True and isString == True: print("Error!")

fi.close()
fo.close()

# https://oj.vnoi.info/problem/vmtest