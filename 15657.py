def overlap_combination(k, arr=[], prev=[]):
    if len(prev)==k:
        return [prev]
    ss = []
    for idx in range(len(arr)):
        ss += overlap_combination(k, arr[idx:], prev + [arr[idx]])
    return ss

from sys import stdin
N, M = map(int, stdin.readline().split())
arr = list(map(int, stdin.readline().split()))
arr.sort()

pairs = overlap_combination(M, arr, [])
for pair in pairs:
    result = ''
    for i in range(M):
        result += str(pair[i])
        result += ' '
    print(result)