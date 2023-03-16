from sys import stdin

K, M = map(int, stdin.readline().split())
charger = list(map(int, stdin.readline().split()))
charger.sort()
posAndFoward = []
for _ in range(M):
    posAndFoward.append(list(map(int, stdin.readline().split())))

for position, dist in posAndFoward:
    minPos = position - dist
    maxPos = position + dist
    maxCharger = len(charger)
    minCharger = -1
    for charge in reversed(charger):
        if charge > maxPos:
            maxCharger = charger.index(charge)
    for charge in charger:
        if charge < minPos:
            minCharger = charger.index(charge)
    print(maxCharger - minCharger - 1)
