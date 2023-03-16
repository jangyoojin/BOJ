from sys import stdin

n = int(input())
stage = list(map(int, stdin.readline().split()))
dp = [0 for _ in range(n+1)]
if n == 1: print(stage[0])
elif n==2: print(stage[1])
else:
    dp[1] = stage[0]
    dp[2] = stage[1] + stage[0]
    for i in range(3,n+1):
        dp[i] = max(dp[i-2] + stage[i-1], dp[i-3] + stage[i-2] + stage[i-1])
    print(dp[n])