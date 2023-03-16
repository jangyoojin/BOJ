from sys import stdin
import collections

def makeset(u):
    pi[u] = u
    rank[u] = 0
    if u in potals:
        rank[u] = 5000

def find(u):
    while u != pi[u]:
        u = pi[u]
    return u
def union(x, y):
    rootX = find(x)
    rootY = find(y)   
    if rank[rootX] > rank[rootY]:
        pi[rootY] = rootX
    else: 
        pi[rootX] = rootY
        if rank[rootY] == rank[rootX]:
            rank[rootY] = rank[rootY] + 1
    


t = int(input())
for _ in range(t):
    i, p, b = map(int, stdin.readline().split())
    potals = list(map(int, stdin.readline().split()))
    possibleEdges = []
    for _ in range(b):
        possibleEdges.append(list(map(int, stdin.readline().split())))

    pi = [-1 for _ in range(i)]
    rank = [0 for _ in range(i)]
    for id in range(i):
        makeset(id)
    
    potalCost = 0
    possibleEdges.sort(key = lambda x: x[2])
    X = []
    for i1, i2, cost in possibleEdges:
        if find(i1) != find(i2) and (find(i1) not in potals or find(i2) not in potals):
            union(i1, i2)
            potalCost += cost
            X.append([i1,i2,cost])
    
    bridegeCost = 0
    possibleEdges.sort(key = lambda x: -x[2])
    for i1, i2, cost in possibleEdges:
        if find(i1) != find(i2):
            union(i1, i2)
            bridegeCost += cost
    
    print(bridegeCost)
    # print(X)
    
        
