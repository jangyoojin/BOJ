def permutation_helper(k, arr=[], prev=[]):
    if len(prev) == k:
        return [prev]
    ss = []
    for idx in range(len(arr)):
        ss += permutation_helper(k, arr[:idx]+arr[idx+1:], prev + [arr[idx]])
    return ss

def permutation(n, k):
    arr = [i for i in range(1, n+1)]
    return permutation_helper(k, arr, [])

from sys import stdin

N, M = map(int, stdin.readline().split())
permu = permutation(N, M)

for pair in permu:
    result = ''
    for i in range(M):
        result += str(pair[i])
        result += ' '
    print(result)