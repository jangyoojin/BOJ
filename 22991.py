from sys import stdin

N, M = map(int, stdin.readline().split())
req = []
bus = []
for i in range(N):
    req.append(list(map(int, stdin.readline().split())))
for i in range(M):
    bus.append(list(map(int, stdin.readline().split())))

req.sort()
bus.sort()
reqVi = [0 for _ in range(N)]

result = 0
for i in range(M):
    reqMax = []
    for i in req:
        if i[1] >= bus[i][1]:
            reqMax.append(i)
    reqMax.sort()


print(result)