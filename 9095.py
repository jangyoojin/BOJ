'''조합 구현하기'''
def combination_num(num1, num2):
    result = 1
    for i in range(num2):
        result *= num1-i
        result //= i+1
    return result


T = int(input())
testcase = []

for _ in range(T):
    testcase.append(int(input()))

for N in testcase:
    '''합이 N이 되는 모든 1, 2, 3의 조합 구하기'''
    combination = []
    n3 = 0
    while n3*3 <= N:
        n2 = 0
        while n2*2 <= N-n3*3:
            n1 = N - n3*3 - n2*2
            combination.append([n1,n2,n3])
            n2 += 1
        n3 += 1
    '''각 조합에 대한 경우의 수 구하기'''
    cnt = 0
    for i in combination:
        if i[2]==0 and i[1]==0: 
            cnt += 1
            continue
        '''3의 위치 정하기'''
        case = combination_num(i[0]+i[1]+i[2], i[2])
        '''2의 위치 정하기'''
        case *= combination_num(i[0]+i[1], i[1])
        cnt += case
    print(cnt)
