#include <bits/stdc++.h>

using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int numbers[100] = {0, };

    cin >> n;
    for(int i=0; i<n; i++) cin >> numbers[i];
    sort(numbers, numbers+n);

    vector<bool> isPrime(numbers[n-1]+1, true);
    isPrime[0] = isPrime[1] = false;

    int cnt = 0;
    for(int i = 2; i<= numbers[n-1]; i++){
        if(!isPrime[i]) continue;
        for(int j = i + i; j <=numbers[n-1]; j += i){
            if(!isPrime[j]) continue;
            isPrime[j] = false;
        }
    }
    for(int i = 0; i<n; i++){
        if(isPrime[numbers[i]]) cnt++;
    }
    
    cout << cnt;
}