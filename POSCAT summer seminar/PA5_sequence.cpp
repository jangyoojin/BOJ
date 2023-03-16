#include <iostream>
using namespace std;

int main() {
    int N;
    int S[1000001];
    cin >> N;
    if(N==1) cout<<"3"<<endl;
    else if(N==2) cout <<"9"<<endl;
    else if(N==3) cout <<"26"<<endl;
    else {
        S[1] = 3;
        S[2] = 9;
        S[3] = 26;
        for (int i = 4; i < N+1; i++)
            S[i] = (S[i-1] + S[i-2] + S[i-3]) *2;
        cout << S[N]%1000000007<<endl;
    }
}