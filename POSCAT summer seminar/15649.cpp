#include <bits/stdc++.h>
#define MAX 9

using namespace std;
int n, m;
int arr[MAX];
bool visited[MAX];

void dfs(int k){
    if(k==m){
        for(int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = 1; i<= n; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[k] = i;
            dfs(k+1);
            visited[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    dfs(0);
}