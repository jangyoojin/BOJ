def combination_helper(k, arr=[], prev=[]):
    if len(prev) == k:
        return [prev]
    ss = []
    for idx in range(len(arr)):
        ss += combination_helper(k, arr[idx+1:], prev + [arr[idx]])
    return ss

def combination(n, k):
    arr = [i for i in range(1, n+1)]
    return combination_helper(k, arr, [])

from sys import stdin

N, M = map(int, stdin.readline().split())
combi = combination(N, M)

for pair in combi:
    result = ''
    for i in range(M):
        result += str(pair[i])
        result += ' '
    print(result)
