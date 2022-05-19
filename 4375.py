result = []

while True:
    try:
        n = int(input())
        x = 1
        rest = 1
        cnt = 0
        while rest != 0:
            rest = x%n
            x = x*10 + 1
            cnt += 1
        result.append(cnt)
    except (EOFError, ValueError):
        break

for i in result:
    print(i)