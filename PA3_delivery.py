from sys import stdin

T = int(input())
for _ in range(T):
    n, C = map(int, stdin.readline().split())
    weights = list(map(int, stdin.readline().split()))
    values = list(map(int, stdin.readline().split()))

    
    #Knapsack Algorithm
    #dp[item][capacity] : weight[capacity]만큼 더 넣을 수 있을 때 item번째 물건을 넣거나 안 넣은 경우 중 큰 값 저장
    dp = [[0 for _ in range(C+1)] for _ in range(n+1)]
    for item in range(1, n+1):
        for capacity in range(C+1):
            if capacity - weights[item-1] >= 0:
                dp[item][capacity] = max(dp[item-1][capacity], dp[item-1][capacity-weights[item-1]]+values[item-1])
            else:
                dp[item][capacity] = dp[item-1][capacity]
    print(dp[n][C])
    