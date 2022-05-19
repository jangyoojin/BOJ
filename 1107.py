"""MAX = 50_0000

N = input()
ch_num = list(map(int, list(N)))
N = int(N)
num = int(input())
if num != 0:
    broken = list(map(int, input().split()))
else:
    broken = []
numbers = list(range(10))

for i in broken:
    numbers.remove(i)

'''무조건 숫자 키 안 누르는 게 최소인 경우'''
if numbers==[] or 99<=N<=102:
    cnt = N-100 if N>100 else 100-N
else:
    small = 0
    big = 0
    count = 0
    isSame = 1
    for i in ch_num:
        if isSame==0:
            small = small*10 + numbers[-1]
            big = big*10 + numbers[0]
            count += 1
        elif i in numbers:
            count += 1
            small = small*10 + i
            big = big*10 + i
        else:
            min = 10
            m_s = MAX
            m_b = MAX
            '''작은 수 구하기'''
            for j in numbers:
                sub = i-j
                if min > sub and sub>0:
                    min = sub
                    m_s = j
                elif sub<0:
                    m_b = j
                    break
            small = small*10 + m_s
            big = big*10 + m_b
            count += 1
            isSame = 0
                    
    '''가장 가까운 수를 구해서 버튼 누르는 횟수 계산'''
    count = count + (N-small if ((big-N)>(N-small) and (N-small)>0) else big-N)
    operator_btn = N-100 if N>100 else 100-N
    cnt = count if count < operator_btn else operator_btn

print(cnt)"""

import sys
input = sys.stdin.readline
N = int(input())
num = int(input())
broken = []
if num!=0: broken = list(input())

def check(i):
    for k in str(i):
        if k in broken:
            return False
    return True

result = abs(N-100)
for i in range(100_0000):
    if check(i): result = min([result, len(str(i))+abs(i-N)])

print(result)

"""N이 주어졌을 때 만들어질 수 있는 최악의 경우를 생각해서
그 채널까지 0부터 탐색하는 알고리즘
최악의 경우: N은 50_0000이고 9를 제외한 모든 버튼이 고장난 
경우 99999까지 입력후 -로 이동하는 게 가장 적은 수의 버튼을 누르게 된다"""