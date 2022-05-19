"""
from sys import stdin

size = int(input())
candy = []
for i in range(size):
    candy.append(list(input()))

'''연속된 캔디가 최대인 raw, col을 찾기'''
max_raw = 0
max_raw_count = 0
max_col = 0
max_col_count = 0
for i in range(size):
    raw_count = 1
    col_count = 1
    raw_sidx = 0
    col_sidx = 0
    for j in range(size-1):
        if candy[i][j] == candy[i][j+1]:
            raw_count += 1
        else:
            raw_count = 0
            raw_sidx = j+1

        if max_raw_count < raw_count:
            max_raw_count = raw_count
            max_raw = i
            max_raw_sidx = raw_sidx
        
        if candy[j][i] == candy[j+1][i]:
            col_count += 1
        else:
            col_count = 0
            col_sidx = j+1
        if max_col_count < col_count:
            max_col_count = col_count
            max_col = i
            max_col_sidx = col_sidx

max_raw_result = max_raw_count
if max_raw_count==size:
    max_raw_result=max_raw_count
elif candy[max_raw][max_raw_sidx-2]==candy[max_raw][max_raw_sidx] or candy[max_raw][max_raw_sidx+max_raw_count-1]== candy[max_raw][max_raw_sidx+max_raw_count+1]:
    if max_raw!=size-1 and candy[max_raw+1][max_raw_sidx-1]==candy[max_raw][max_raw_sidx]:
        max_raw_result += 1
        i = max_raw_sidx-2
        while candy[max_raw][i]==candy[max_raw][max_raw_sidx]:
            max_raw_result += 1
            i -= 1
            if i < 0: break
    elif max_raw!=size-1 and candy[max_raw+1][max_raw_sidx+max_raw_count]==candy[max_raw][max_raw_sidx]:
        max_raw_result += 1
        i = max_raw_sidx + max_raw_count
        while candy[max_raw][i]==candy[max_raw][max_raw_sidx]:
            max_raw_result += 1
            i += 1
            if i >= size: break
    elif max_raw!=0 and candy[max_raw-1][max_raw_sidx-1]==candy[max_raw][max_raw_sidx]:
        max_raw_result += 1
        i = max_raw_sidx-2
        while candy[max_raw][i]==candy[max_raw][max_raw_sidx]:
            max_raw_result += 1
            i -= 1
            if i < 0: break
    elif max_raw!=size-1 and candy[max_raw-1][max_raw_sidx+max_raw_count]==candy[max_raw][max_raw_sidx]:
        max_raw_result += 1
        i = max_raw_sidx + max_raw_count
        while candy[max_raw][i]==candy[max_raw][max_raw_sidx]:
            max_raw_result += 1
            i += 1
            if i >= size: break
    else:
        max_raw_result += 1
else:
    if max_raw!=size-1 and candy[max_raw+1][max_raw_sidx-1]==candy[max_raw][max_raw_sidx]:
        max_raw_result += 1
    elif max_raw!=0 and candy[max_raw-1][max_raw_sidx-1]==candy[max_raw][max_raw_sidx]:
        max_raw_result += 1
    elif max_raw!=size-1 and candy[max_raw+1][max_raw_sidx+max_raw_count]==candy[max_raw][max_raw_sidx]:
        max_raw_result += 1
    elif max_raw!=0 and candy[max_raw-1][max_raw_sidx+max_raw_count]==candy[max_raw][max_raw_sidx]:
        max_raw_result += 1

max_col_result = max_col_count
if max_col_count==size:
    max_col_result=max_col_count
elif candy[max_col_sidx-2][max_col]==candy[max_col_sidx][max_col] or candy[max_col_sidx+max_col_count-1][max_col]== candy[max_col_sidx+max_col_count+1][max_col]:
    if max_col!=size-1 and candy[max_col_sidx-1][max_col+1]==candy[max_col_sidx][max_col]:
        max_col_result += 1
        i = max_col_sidx-2
        while candy[i][max_col]==candy[max_col_sidx][max_col]:
            max_col_result += 1
            i -= 1
            if i < 0: break
    elif max_col!=size-1 and candy[max_col_sidx+max_col_count][max_col+1]==candy[max_col_sidx][max_col]:
        max_col_result += 1
        i = max_col_sidx + max_col_count
        while candy[i][max_col]==candy[max_col_sidx][max_col]:
            max_col_result += 1
            i += 1
            if i >= size: break
    elif max_col!=0 and candy[max_col_sidx-1][max_col-1]==candy[max_col_sidx][max_col]:
        max_col_result += 1
        i = max_col_sidx-2
        while candy[i][max_col]==candy[max_col_sidx][max_col]:
            max_col_result += 1
            i -= 1
            if i < 0: break
    elif max_col!=size-1 and candy[max_col_sidx+max_col_count][max_col-1]==candy[max_col_sidx][max_col]:
        max_col_result += 1
        i = max_col_sidx + max_col_count
        while candy[i][max_col]==candy[max_col_sidx][max_col]:
            max_col_result += 1
            i += 1
            if i >= size: break
    else:
        max_col_result += 1
else:
    if max_col!=size-1 and candy[max_col_sidx-1][max_col+1]==candy[max_col_sidx][max_col]:
        max_col_result += 1
    elif max_col!=0 and candy[max_col_sidx-1][max_col-1]==candy[max_col_sidx][max_col]:
        max_col_result += 1
    elif max_col!=size-1 and candy[max_col_sidx+max_col_count][max_col+1]==candy[max_col_sidx][max_col]:
        max_col_result += 1
    elif max_col!=0 and candy[max_col_sidx+max_col_count][max_col-1]==candy[max_col_sidx][max_col]:
        max_col_result += 1

max_result = max_raw_result if max_raw_result > max_col_result else max_col_result
print(max_result)"""


N = int(input())
board = []
for _ in range(N):
    board.append(list(input()))

'''direction: (x,y)'''
'''right: (0,1), up: (-1,0), left: (0,-1), down: (1,0)'''
dir_x = [0, -1, 0, 1]
dir_y = [1, 0, -1, 0]

max_value = 0
'''모든 칸에 대해서'''
for x in range(N):
    for y in range(N):
        '''4가지 방향의 사탕을 모두 바꿔보고'''
        for j in range(4):
            a = x + dir_x[j]
            b = y + dir_y[j]
            if 0 <= a < N and 0<= b <N:
                temp = board[x][y]
                board[x][y] = board[a][b]
                board[a][b] = temp
                '''바꾼 상태에서 가장 많이 연속된 칸의 갯수를 센다'''
                for k in range(N):
                    prev_x = None
                    prev_y = None
                    for l in range(N):
                        if prev_x == board[k][l]:
                            cnt_x += 1
                        else:
                            cnt_x = 1
                            prev_x = board[k][l]

                        if prev_y == board[l][k]:
                            cnt_y += 1
                        else:
                            cnt_y = 1
                            prev_y = board[l][k]
                        max_value = max([cnt_x, cnt_y, max_value])
                    if cnt_x == N or cnt_y == N:
                        break
                board[a][b] = board[x][y]
                board[x][y] = temp

print(max_value)
