#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

int main(){
    int N;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> dots;

    scanf("%d\n", &N);
    for(int i=0;i<N;i++){
        pair<int,int> p;
        scanf("%d %d\n", &p.first, &p.second);
        dots.push(p);
    }
    for(int i =0;i<N;i++){
        printf("%d %d\n", dots.top().first, dots.top().second);
        dots.pop();
    }    
}