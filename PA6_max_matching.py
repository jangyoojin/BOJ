from sys import stdin
import collections



t = int(input())
for _ in range(t):
    n, m, l = map(int, stdin.readline().split())
    matched = [-1 for _ in range(m)] # matched terminates
    # 비어있는 terminate 찾을 때까지 모든 edge 순회
    # 비어있는 terminate 찾으면 true 및 종료, 못찾으면 false 리턴
    def matching(s):
        for t in edges[s]:
            if searched[t]: continue
            searched[t] = True
            if matched[t] == -1 or matching(matched[t]):
                matched[t] = s
                return True
        return False

    edges = collections.defaultdict(list)
    for _ in range(l):
        s, t = map(int, stdin.readline().split())
        edges[s].append(t)
    
    matchNum = 0
    for i in range(n):
        searched = [False for _ in range(m)] # search completed terminates
        if matching(i): matchNum += 1
    print(matchNum)
