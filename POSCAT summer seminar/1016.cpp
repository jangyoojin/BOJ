#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int min, max;
    cin >> min >> max;
    int isCounted[max - min + 1] = {0,};
    int cnt = 0;
    for(int i = 2; i <= sqrt(max)+1; i++){
        for(int j = min; j<=max; j++){
            if(j % (i*i) == 0 && !isCounted[j]) {
                isCounted[j] = 1;
                cnt++;
            }
        }
    }
    cout << max - min + 1 - cnt;
    return 0;
}