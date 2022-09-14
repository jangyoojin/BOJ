#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;

int main(){
    set<int> s;
    int N;
    scanf("%d\n", &N);
    for(int i =0;i<N;i++){
        int n;
        scanf("%d ",&n);
        s.insert(n);
    }
    int M;
    scanf("%d\n",&M);
    for(int i=0;i<M;i++){
        int n;
        scanf("%d ", &n);
        printf("%d\n", (s.find(n)!=s.end()));
    }
}