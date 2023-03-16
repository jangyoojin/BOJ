from sys import stdin

t = int(input())

for _ in range(t):
    V, E, k = map(int, stdin.readline().split())
    edges = {v:[] for v in range(V)}
    for _ in range(E):
        s, e, w =map(int, stdin.readline().split())
        edges[e].append((s,w))

    dist = [[float('inf') for _ in range(k+1)] for _ in range(V)]
    for i in range(k+1):
        dist[0][i] = 0

    for i in range(1, k+1):
        for v in range(V):
            # curedges = [e for e in edges if e[1] == v]
            minimum = float('inf')
            for s, w in edges[v]:
                curdist = dist[s][i-1] + w
                if minimum > curdist:
                    minimum = curdist
            if minimum == float('inf'):
                dist[v][i] = dist[v][i-1]
            else:
                dist[v][i] = minimum

    if dist[V-1][k] == float('inf'):
        print("NO")
    else:
        print(dist[V-1][k])            
    