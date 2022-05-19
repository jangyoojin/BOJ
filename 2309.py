from sys import stdin

height = []
sum = 0
for i in range(9):
    height.append(int(input()))
    sum += height[i]

height.sort()

for i in range(9):
    isEnd = 0
    for j in range(i+1,9):
        result = sum - (height[i] + height[j])
        if result == 100:
            for k in range(9):
                if k != i and k != j:
                    print(height[k])
            isEnd = 1
            break
    if isEnd == 1: break
    
