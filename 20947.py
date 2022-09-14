from sys import stdin

N = int(input())
board = []
for i in range(N):
    board.append(list(stdin.readline()))

for i in range(N):
    for j in range(N):
        if 'X' in board[i] and board[i][j] == '.':
            board[i][j] = 'B'

for i in range(N):
    if 'B' in board[i]:
        for k in range(N):
            if board[i][k] == 'B':
                idx = k
                for j in range(idx-1, -1, -1):
                    if board[i][j] == '.': continue
                    else:
                        if board[i][j] == 'X': break
                        if board[i][j] == 'O':
                            board[i][idx] = '.'
                            break
                        
                for j in range(idx+1, N):
                    if board[i][j] == '.': continue
                    else:
                        if board[i][j] == 'X': break
                        if board[i][j] == 'O':
                            board[i][idx] = '.'
                            break
                for j in range(idx-1, -1, -1):
                    if board[j][idx] == '.': continue
                    else:
                        if board[j][idx] == 'X': break
                        if board[j][idx] == 'O':
                            board[i][idx] = '.'
                            break
                for j in range(idx+1, N):
                    if board[j][idx] == '.': continue
                    else:
                        if board[j][idx] == 'X': break
                        if board[j][idx] == 'O':
                            board[i][idx] = '.'
                            break

for i in range(N):
    print(''.join(board[i]))