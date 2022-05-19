def pair_combination(k, arr=[], prev=[]):
    if len(prev)==k:
        return [prev]
    ss = []
    for idx in range(len(arr)):
        ss += pair_combination(k, arr[idx+1:], prev + [arr[idx]])
    return ss

from sys import stdin

N, M, K = map(int, stdin.readline().split())
board = []
for _ in range(N):
    board.append(list(map(int, stdin.readline().split())))
pos = []
for i in range(N):
    for j in range(M):
        pos.append([i,j])
pairs = pair_combination(K, pos, [])

dir = [[0,1],[0,-1],[1,0],[-1,0]]

max = -10001
for pair in pairs:
    isValid = 1
    idx = 0
    for i, j in pair:
        idx += 1
        for i2, j2 in pair[idx:]:
            '''(0,1), (0,-1)'''
            if i==i2 and (j+1==j2 or j-1==j2):
                isValid = 0
                break
            elif j==j2 and (i+1==i2 or i-1==i2):
                isValid = 0
                break
        if isValid==0: break
    if isValid:
        sum = 0
        for r, c in pair:
            sum += board[r][c]
        if max < sum: max = sum
print(max)

