import sys

pos_x_pos_y = [
               [[0,0,0,0],[0,1,2,3]],
               [[0,0,1,1],[0,1,0,1]],
               [[0,0,0,1],[0,1,2,0]],
               [[0,1,1,2],[0,0,1,1]],
               [[0,0,0,1],[0,1,2,1]],
               [[0,0,0,1],[0,1,2,2]],
               [[0,0,1,-1],[0,1,0,1]]
              ]

N, M = map(int, input().split())
board = []
for _ in range(N):
    board.append(list(map(int, sys.stdin.readline().split())))

maximum = 0
for x in range(N):
    for y in range(M):
        '''도형 7가지에 대해서'''
        for i in range(7):
            pos_a = pos_x_pos_y[i][0]
            pos_b = pos_x_pos_y[i][1]
            n_pos_a = list((-1)*e for e in pos_a)
            n_pos_b = list((-1)*e for e in pos_b)
            '''각 도형 별로 4가지 방향 고려'''
            '''0:(pos_a, pos_b)'''
            '''1:(pos_b, -pos_a)'''
            '''2:(-pos_a, -pos_b)'''
            '''3:(-pos_b, pos_a)'''
            for j in range(4):
                if j == 0:
                    a = pos_a
                    b = pos_b
                elif j == 1:
                    a = pos_b
                    b = n_pos_a
                elif j == 2:
                    a = n_pos_a
                    b = n_pos_b
                else:
                    a = n_pos_b
                    b = pos_a
                sum = 0
                inBoard = 1
                for l in range(4):
                    if 0<= x+a[l] <N and 0<= y+b[l] <M:
                        sum += board[x+a[l]][y+b[l]]
                    else:
                        inBoard = 0
                        break
                if inBoard==1:
                    maximum = max([maximum, sum])

print(maximum)
                        

