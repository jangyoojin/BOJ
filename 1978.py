from sys import stdin

num = int(input())
li = list(map(int, stdin.readline().split()))

primeNum = 0

for i in li:
    isPrime = 1
    if i == 1: continue
    else:
        for j in range(2, i):
            if i%j == 0:
                isPrime = 0
                break
    if isPrime == 1: primeNum += 1

print(primeNum)