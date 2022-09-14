from sys import stdin

N, M = map(int, stdin.readline().split())
before = []
for i in range(N):
    before.append(list(map(int, stdin.readline().split())))

after = []
for i in range(N):
    after.append(list(map(int, stdin.readline().split())))

sector = []
idx = 0
index = [([None for _ in range(M)]) for _ in range(N)]
for i in range(N):
    for j in range(M):
        sector[idx].append((i,j))


visit = [([False for i in range(M)]) for j in range(N)]
isFinish = 0
change = 0
for i in range(N):
    for j in range(M):
        if(before[i][j] != after[i][j] and visit[i][j] == False):
            for c,r in sector[before[i][j]]:
                visit[c][r] = True
                if after[i][j] != after[c][r]:
                    print("NO")
                    isFinish = 1
                    break
            if isFinish==0: change = change + 1
        if isFinish: break
    if isFinish: break

if change == 0: print("YES")
elif change == 1: print("YES")
else:
    print("NO")
                    