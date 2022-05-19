from re import T
from sys import stdin
import math

M, N = list(map(int, stdin.readline().split()))



for i in range(M, N+1):
    isPrime = 1
    if i == 1: continue
    elif i == 2:
        print(i)
        continue
    else:
        for j in range(2, int(math.sqrt(i))+1):
            if i%j == 0:
                isPrime = 0
                break
    if isPrime == 1: 
        print(i)

"""
M, N = map(int, input().split())
check = [0] * (N +1)

for i in range(2, N+1):
    if check[i] == 0:
        if i >= M:
            print(i)
        for j in range(i+i, N+1, i):
            if check[j]==0:
                check[j] = 1
"""