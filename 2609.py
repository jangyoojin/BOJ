num = int(input())
y_value = []

for i in range(num):
    y_value.append(int(input()))

MAX = 1000000
f = [0 for i in range(MAX+1)]
for i in range(1, MAX+1):
    j = 1
    while(i*j < MAX+1):
        f[i*j] += i
        j += 1

g = [0 for i in range(MAX+1)]
for i in range(1, MAX+1):
    g[i] = g[i-1] + f[i]


for y in y_value:
    print(g[y])
