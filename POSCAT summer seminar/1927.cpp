#include <stdio.h>
#include <queue>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> numbers;
    int N;
    scanf("%d\n", &N);
    
    for(int i = 0;i<N;i++){
        int n;
        scanf("%d\n",&n);
        if(n) numbers.push(n);
        else{
            if(numbers.size()==0) printf("0\n");
            else{
            printf("%d\n", numbers.top());
            numbers.pop();
            }
        }
    }
}