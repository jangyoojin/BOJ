from sys import stdin

N = int(input())
p = list(map(float, stdin.readline().split()))
result = 0
for i in p:
    result += i
for i in range(1, N):
    result += p[i-1]*(1-p[i]) + (1-p[i-1])*p[i]

print(result)