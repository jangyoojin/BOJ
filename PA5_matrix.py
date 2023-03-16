from sys import stdin
from itertools import permutations

numbers = list(map(int, stdin.readline().split()))
matrixes = list(permutations(numbers,9))
isTrue = 0
for matrix in matrixes:
    if matrix[0]+matrix[1]+matrix[2] == matrix[3]+matrix[4]+matrix[5] and matrix[3]+matrix[4]+matrix[5] == matrix[6]+matrix[7]+matrix[8]\
        and matrix[0]+matrix[3]+matrix[6] == matrix[1]+matrix[4]+matrix[7] and matrix[1]+matrix[4]+matrix[7] == matrix[2]+matrix[5]+matrix[8]\
        and matrix[0]+matrix[4]+matrix[8] == matrix[2]+matrix[4]+matrix[6]:
        isTrue = 1
        print("YES")
        break

if not isTrue:
    print("NO")

