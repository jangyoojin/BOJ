from sys import stdin

T = int(input())
NK = []
for i in range(T):
    NK.append(list(map(int, stdin.readline().split())))


for i in range(T):
    if NK[i][0] <= NK[i][1]:
        print(NK[i][0]*(8+(NK[i][0]-1)*4)//2)
    else:
        result = NK[i][0]*(8+(NK[i][0]-1)*4)//2 - (NK[i][0]-NK[i][1]-1)*(8+((NK[i][0]-NK[i][1]-1)-1)*4)//2
        print(result)

