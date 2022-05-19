from sys import stdin

test = int(input())
testCase = []
for _ in range(test):
    testCase.append(list(map(int, stdin.readline().split())))

for i in range(test):
    M = testCase[i][0]
    N = testCase[i][1]
    x = testCase[i][2]
    y = testCase[i][3]
    year = 1
    a = 1
    b = 1
    isVaild = 0
    '''최소공배수 구하기'''
    number = M if M>N else N
    divisor = N if M>N else M
    remain = -1
    while(remain != 0):
        remain = number % divisor
        number = divisor
        divisor = remain
    MAX_year = M*N//number
    
    while a!=x:
        a += 1
        if b==N: b = 1
        else: b += 1
        year += 1
    
    while year <= MAX_year:
        if b==y:
            print(year)
            isVaild = 1
            break
        """b += (M-N)
        if b <= 0: b += N
        elif b > N: b -= N"""
        b = (b+M) % N
        if b==0: b = 1
        year += M

    if isVaild==0: print(-1)

