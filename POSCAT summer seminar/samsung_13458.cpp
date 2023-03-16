#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,B,C;
    long long result= 0;
    vector<int> players;

    cin>>N;
    for(int i = 0 ; i< N; i++) {
        int tmp;
        cin>>tmp;
        players.push_back(tmp);
    }
    cin>>B>>C;

    for(int i = 0; i< N; i++){
        // if(players[i] >= B && B>C) {
        //     players[i] -= B;
        //     result++;
        // }
        players[i] -= B;
        if(players[i] <= 0) continue;
        if(players[i] % C == 0) result += players[i]/C;
        else result += players[i]/C + 1;
    }
    cout<<result + N<<endl;
}