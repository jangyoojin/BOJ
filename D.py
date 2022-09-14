from sys import stdin

Q = int(input())
req = []
fx = [0,1]
plusIn = [0]
miusIn = [0]

for i in range(Q):
    req.append(list(map(int, stdin.readline().split())))

for request in req:
    if request[0] == 1:
        x = [fx[i]*request[1] for i in range(len(fx))]
        const = [fx[i]*request[2] for i in range(len(fx))]
        fx = [x[0]]
        for i in range(1,len(x)):
            fx.append(x[i]+const[i-1])
        fx.append(const[-1])
    else:
        result = fx[-1]
        ans = request[1]
        for i in range(len(fx)-2, -1, -1):
            result += fx[i]*ans
            ans = ans*ans
        
        if result>0: print('+')
        elif result == 0: print('0')
        else:
            print('-')