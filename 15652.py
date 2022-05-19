def overlap_combination_helper(k, arr=[], prev=[]):
    if len(prev) == k:
        return [prev]
    ss =[]
    for idx in range(len(arr)):
        ss += overlap_combination_helper(k, arr[idx:], prev + [arr[idx]])
    return ss

def overlap_combination(n, k):
    arr = [i for i in range(1, n+1)]
    return overlap_combination_helper(k, arr, [])

from sys import stdin

N, M = map(int, stdin.readline().split())
pairs = overlap_combination(N, M)

for pair in pairs:
    result = ''
    for i in range(M):
        result += str(pair[i])
        result += ' '
    print(result)
