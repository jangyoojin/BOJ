#include <queue>
#include <stdio.h>

using namespace std;

int main(){
    int N,n;
    priority_queue<int, vector<int>, greater<int>> que;

    scanf("%d\n",&N);
    for(int i=0;i<N;i++){
        scanf("%d\n", &n);
        que.push(n);
    }
    for(int i=0;i<N;i++){
        printf("%d\n", que.top());
        que.pop();
    }
}