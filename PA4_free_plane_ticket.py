from sys import stdin
import heapq

t = int(input())

for _ in range(t):
    V, E = map(int, stdin.readline().split())
    edges = {v:[] for v in range(V)}
    for _ in range(E):
        s, e, w =map(int, stdin.readline().split())
        edges[s].append([e,w])
    
    useFreeTicketDist = float('inf')
    for v in range(V):
        for e in range(len(edges[v])):
            oldEdge = edges[v][e][1]
            edges[v][e][1] = 0
            dist = [float('inf') for _ in range(V)]
            dist[0] = 0
            H = []
            visited = [False for _ in range(V)]
            heapq.heappush(H, (0, dist[0]))
            while H:
                u, curDist = heapq.heappop(H)
                if visited[u] == True:
                    continue
                visited[u] = True
                for node, weight in edges[u]:
                    if dist[node] > curDist + weight:
                        dist[node] = curDist + weight
                    heapq.heappush(H, (node, dist[node]))
            if useFreeTicketDist > dist[V-1]:
                useFreeTicketDist = dist[V-1]
            edges[v][e][1] = oldEdge

    if useFreeTicketDist == float('inf'):
        print(-1)
    else:
        print(useFreeTicketDist)


