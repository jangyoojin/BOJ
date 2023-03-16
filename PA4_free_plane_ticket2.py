from sys import stdin

t = int(input())

for _ in range(t):
    V, E = map(int, stdin.readline().split())
    dist = [[float('inf') for _ in range(V)] for _ in range(V)]
    edges = []
    for _ in range(E):
        s, e, w = map(int, stdin.readline().split())
        dist[s][e] = w
        edges.append([s,e,w])
    for i in range(V):
        dist[i][i] = 0

    for mid in range(V):
        for start in range(V):
            for end in range(V):
                dist[start][end] = min(dist[start][end], dist[start][mid]+dist[mid][end])
    
    
    minimum = min(dist[0][s]+dist[e][V-1] for s,e,_ in edges)
    if minimum == float('inf'):
        print(-1)
    else:
        print(minimum)

    