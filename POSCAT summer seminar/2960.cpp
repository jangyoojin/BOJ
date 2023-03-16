#include <bits/stdc++.h>

using namespace std;

int findPrime(int n, int k){
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    int cnt = 0;

    for(int i=2; i<=n; i++) {
        if(!isPrime[i]) continue;
        for(int j=i; j<=n; j+=i){
            if(!isPrime[j]) continue;
            isPrime[j] = false;
            cnt++;
            if(cnt==k) return j;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    cout << findPrime(n, k);

    return 0;
}