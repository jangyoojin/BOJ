#include <bits/stdc++.h>
using namespace std;
#define SIZE 3001

int N;
vector<int> graph[SIZE];
bool visited[SIZE] = {false,};
int parent[SIZE];
int dist[SIZE];
queue<int> q;

int DFS(int u, int prev) {
    visited[u] = true;
    parent[u] = prev;
    int size = graph[u].size();
    int x, res;
    for(int i = 0; i < size; i++){
        x = graph[u][i];
        if (x == prev) continue;
        else if (visited[x]){
            parent[x] = u;
            return x;
        }
        res = DFS(x, u);
        if (res > 0) return res;
    }
    return -1;
}

void BFS() {
    while(!q.empty()) {
        int u = q.front(); q.pop();
        int size = graph[u].size();
        int x;
        for (int i = 0; i < size; i++){
            x = graph[u][i];
            if (visited[x]) continue;
            if (dist[x] == 0) continue;

            visited[x] = true;
            dist[x] = dist[u] + 1;
            q.push(x);
        }
    }
}

int main() {
    ios::sync_with_stdio();
    cin.tie();

    int a, b;
    cin>> N;

    //행렬에 그래프 저장
    for (int i = 0; i<N; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //cycle 찾기
    int start = DFS(1, -1);

    //초기화
    for (int i = 1; i<=N; i++){
        visited[i] = false;
        dist[i] = -1;
    }

    //순환선 역 거리 0으로 기록
    int k = start;
    do {
        dist[k] = 0;
        if(graph[k].size() > 2){
            visited[k] = true;
            q.push(k);
        }
        k = parent[k];
    } while (k != start);

    BFS();

    for (int i = 1; i<=N; i++){
        cout << dist[i] << ' ';
    }
    return 0;
}