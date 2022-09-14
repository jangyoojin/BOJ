from sys import stdin


a, d, k = map(int, stdin.readline().split())
d = d/100
k = k/100

result = a*d
cnt = 1
lose = 1
while d < 1:
    cnt = cnt + 1
    lose *= 1 - d
    d = d + d*k
    if(d>1): d = 1
    result += a*cnt*lose*d

print(result)