N = int(input())

k = len(str(N))-1

sum = 0
for i in range(k):
    sum += 9*(10**i) * (i+1)
    N -= 9*(10**i)
sum += N * (k+1)

print(sum)