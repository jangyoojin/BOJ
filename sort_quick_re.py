from sys import stdin

T = int(input())
for _ in range(T):
    n, C = map(int, stdin.readline().split())
    weight = [0] + list(map(int, stdin.readline().split()))
    value = [0] + list(map(int, stdin.readline().split()))
    dp = [[0 for _ in range(C+1)] for _ in range(n+1)]
    for i in range(1,n+1):
        for j in range(1,C+1):
            if j - weight[i] >= 0:
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i])
            else:
                dp[i][j] = dp[i-1][j]
    print(dp[n][C])