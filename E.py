from datetime import datetime

N = int(input())
times = []
for i in range(N):
    time = list(input().split())
    time_string = time[0]+' '+time[1]
    times.append([datetime.strptime(time_string, "%Y/%m/%d %H:%M:%S"), int(time[2])])

times.sort()

p = []
N = len(times)
i = 0
for time_string, level in times:
    diff = times[-1][0]-time_string
    p.append(max(0.5**((diff.days*86400+diff.seconds)/(365*86400)), 0.9**(N-i-1)))
    i += 1
    
up = 0
down=0
for i in range(len(p)):
    up += p[i]
    down += p[i]*times[i][1]
if up != 0:
    X = round(down/up)
else:
    X = 0
print(X)