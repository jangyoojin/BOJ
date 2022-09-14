N, K = map(int, input().split())
A = []
for _ in range(N):
    A.append(int(input()))

i = N-1
cnt = 0
while(1):
    if i == -1 : break
    elif K < A[i]: i -= 1
    else:
        cnt += K // A[i]
        K = K % A[i]

print(cnt)
