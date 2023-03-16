#include <bits/stdc++.h>
using namespace std;

void findPrime(vector<bool> &isPrime){
    isPrime[0] = isPrime[1] = 0;

    for(int i = 2; i<= 1000001; i++){
        if(!isPrime[i]) continue;
        for(int j = i+i; j <= 1000001; j+=i){
            if(!isPrime[j]) continue;
            isPrime[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<bool> isPrime(1000001, true);
    findPrime(isPrime);

    int n;
    while(true){
        cin >> n;
        for(int i = 2; i <= n; i++){
            if(isPrime[i] && isPrime[n-i]){
                cout << n << " = " << i << " + " << n-i <<endl;
                break;
            }
        }
        if(n==0) break;
    }
}