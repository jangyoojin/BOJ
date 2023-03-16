from sys import stdin

dx = [1,-1,0,0]
dy = [0,0,1,-1]


t = int(input())
for _ in range(t):
    N, M = map(int, stdin.readline().split())
    Map = []
    for _ in range(N):
        Map.append(list(map(int, stdin.readline().split())))
    
    lengthDP = [[0 for _ in range(M)] for _ in range(N)]
    prevDP = [[None for _ in range(M)] for _ in range(N)]
    
    # def explore(x, y, Map):
    #     if lengthDP[x][y] > 0: return lengthDP[x][y]
    #     maxLen = 0

    #     for width in range(1, 5):
    #         for i in range(4):
    #             nextX = x + dx[i]*width
    #             nextY = y + dy[i]*width
    #             if nextX >= N or nextX < 0 or nextY >= M or nextY < 0 or Map[x][y] >= Map[nextX][nextY]:
    #                 continue
    #             print(x,',',y,' ', nextX,',',nextY)
    #             print(lengthDP)
    #             tempLen = explore(nextX, nextY, Map)
    #             if maxLen < tempLen:
    #                 maxLen = tempLen
    #                 prevDP[nextX][nextY] = [x,y]
        
    #     lengthDP[x][y] = maxLen + 1
    #     return lengthDP[x][y]
    innerEdge = [[0 for _ in range(M)] for _ in range(N)]
    for i in range(N):
        for j in range(M):
            for width in range(1, 5):
                for dir in range(4):
                    nextX = i + dx[dir]
                    nextY = j + dy[dir]

                    if nextX >= 0 and nextX < N and nextY >=0 and nextY < M and Map[i][j] < Map[nextX][nextY]:
                        innerEdge[i][j] += 1


    # longest = 0
    # for i in range(N):
    #     for j in range(M):
    #         temp = explore(i, j, Map)
    #         longest = max(longest, temp)
    
    queue = []
    for i in range(N):
        for j in range(M):
            if innerEdge[i][j] == 0:
                queue.append([i,j])

    longest = 0
    while len(queue) != 0:
        size = len(queue)
        for k in range(size):
            i, j = queue.pop()
            for width in range(1,5):
                for idx in range(4):
                    nextX = i + dx[idx]*width
                    nextY = j + dy[idx]*width
                    if nextX >= 0 and nextX < N and nextY >=0 and nextY < M and Map[nextX][nextY] < Map[i][j]:
                        innerEdge[nextX][nextY] -= 1
                        if innerEdge[nextX][nextY]:
                            queue.append([nextX,nextY])
            longest += 1

    print(longest)