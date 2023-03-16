from sys import stdin
import heapq

t = int(input())

for _ in range(t):
    V, E = map(int, stdin.readline().split())
    edges = {v:[] for v in range(2*V)}
    for _ in range(E):
        s, e, w =map(int, stdin.readline().split())
        edges[s].append([e,w])
        edges[s].append([e+V,0])
        edges[s+V].append([e+V,w])
    dist = [float('inf') for _ in range(2*V)]
    dist[0] = 0
    H = []
    heapq.heappush(H, (0, dist[0]))
    while H:
        u, curDist = heapq.heappop(H)
        if dist[u] < curDist:
            continue
        for node, weight in edges[u]:
            if dist[node] > curDist + weight:
                dist[node] = curDist + weight
                heapq.heappush(H, (node, dist[node]))
    
    if dist[V-1] == float('inf'):
        print(-1)
    else:
        print(dist[2*V-1])

    