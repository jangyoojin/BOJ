from sys import stdin
import heapq

t = int(input())
for _ in range(t):
    n = int(input())
    bids = []
    for _ in range(n):
        bids.append(list(map(int, stdin.readline().split())))
    # fee는 내림차순 deadline은 오름차순으로 정렬
    bids.sort(key = lambda x: -x[0])
    bids.sort(key = lambda x: x[1])
    #priority queue에 fee를 deadline 오름차순으로 대입
    queue = []
    for bid in bids:
        heapq.heappush(queue, bid[0])
        if bid[1] < len(queue):
            heapq.heappop(queue)
    
    print(sum(queue))
