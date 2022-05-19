a, b = input().split()
a = int(a)
b = int(b)

if(a > b): 
    divided = a
    divisor = b
else: 
    divided = b
    divisor = a
remain = -1

while(remain != 0):
    remain = divided % divisor
    divided = divisor
    divisor = remain

gbd = divided
lcm = int(a*b/gbd)

print(gbd)
print(lcm)
