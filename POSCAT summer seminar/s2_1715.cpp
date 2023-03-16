#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, c, sum=0;
    priority_queue<int,vector<int>,greater<>> cards;
    cin>>N;
    for(int i = 0; i < N; i++) {
        cin>>c;
        cards.push(c);
    }

    int a, b;
    while(cards.size() > 1){
        a = cards.top();
        cards.pop();
        b = cards.top();
        cards.pop();
        cards.push(a+b);
        sum += a+b;
    }
    cout<<sum<<endl;
}