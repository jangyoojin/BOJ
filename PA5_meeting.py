from sys import stdin

n = int(input())
pos = []
for _ in range(n):
    pos.append(list(map(int, stdin.readline().split())))

Ax, Ay, Bx, By = map(int, stdin.readline().split())
result = 0 
for i in range(1, n-1):

    for p in pos[:i]:
        dist1 = abs(p[0] - Ax) + abs(p[1]-Ay)
        dist2 = abs(p[0] - Bx) + abs(p[1]-By)
        if dist1 > dist2:
            result += dist2
        else:
            result += dist1

print(result)