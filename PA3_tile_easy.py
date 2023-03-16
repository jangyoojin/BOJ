
T = int(input())

dp = [0,2,7] + [0 for _ in range(1000005)]
new_pattern = [0,0,2,2] + [0 for _ in range(1000005)]
for i in range(3, 1000001):
    new_pattern[i] = dp[i-3]*2 + new_pattern[i-1]
    dp[i] = (dp[i-1]*2 + dp[i-2]*3 + new_pattern[i]) % 1000000000


for _ in range(T):
    n = int(input())
    print(dp[n])