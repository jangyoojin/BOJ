from sys import stdin

q = []
N = int(input())
cmd = [[] for i in range(N)]

for i in range(N):
    cmd[i] = list(map(str, stdin.readline().split()))

#시간 초과는 list에서 pop할 때 요소를 지우지 않고 인덱스만 증가시키는 것으로 해결
front = 0
for i in range(N):
    if len(q)-front:
        if cmd[i][0]=="push":
            q.append(int(cmd[i][1]));
        elif cmd[i][0]=="pop":
            print(q[front])
            front = front+1
        elif cmd[i][0]=="size":
            print(len(q)-front)
        elif cmd[i][0]=="empty":
            print(0)
        elif cmd[i][0]=="front":
            print(q[front])
        elif cmd[i][0]=="back":
            print(q[-1])
    else:
        if cmd[i][0]=="push":
            q.append(int(cmd[i][1]));
        elif cmd[i][0]=="pop":
            print(-1)
        elif cmd[i][0]=="size":
            print(0)
        elif cmd[i][0]=="empty":
            print(1)
        elif cmd[i][0]=="front":
            print(-1)
        elif cmd[i][0]=="back":
            print(-1)