#include <iostream>
#include <vector>
using namespace std;


int main(){
    int N, data;
    vector<int> v;
    vector<int> dp;
    cin>>N;

    v.push_back(0);
    dp.push_back(0);
    
    for(int i = 1; i<=N; i++){
        cin>>data;
        v.push_back(data);
        dp.push_back(max(dp[i-1]+v[i], v[i]));
    }

    int maximum = dp[1];
    for(int j = 1; j <= N; j++){
        if(maximum < dp[j]) maximum = dp[j];
    }

    printf("%d", maximum);

}
