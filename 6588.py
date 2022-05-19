MAX = 100_0000


'''find all prime number from 3 to MAX'''
prime = [True for _ in range(MAX+1)]
for i in range(2, MAX+1):
    if i*i>MAX:
        break
    if prime[i] is True:
        for j in range(i*i, MAX+1, i):
            prime[j] = False


even = []
number = int(input())

while number!=0:
    even.append(number)
    number = int(input())


for i in even:
    for j in range(3, MAX+1):
        if prime[j] is True:
            k = i - j
            if prime[k] is True:
                print(str(i)+" = "+str(j)+" + "+str(k))
                break
