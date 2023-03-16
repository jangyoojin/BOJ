
def mul(x, y):
    result = [[0,0,0] for _ in range(3)]
    for i in range(3):
        for j in range(3):
            for k in range(3):
                result[i][j] += x[i][k]*y[k][j]
                result[i][j] %= 1234567890
    return result


T = int(input())

for _ in range(T):
    n = int(input())
    base = [[7,0,0],[2,0,0],[1,0,0]]
    mat = [[3,1,-1],[1,0,0],[0,1,0]]
    result = [[1,0,0],[0,1,0],[0,0,1]]
    #이진수 성질 이용, 이진수에서 마지막 자리가 1일때만 result에 업데이트 하기
    while(n):
        if n%2: result = mul(result, mat)
        mat = mul(mat,mat)
        n //= 2
    result = mul(result, base)
    print(result[2][0])
