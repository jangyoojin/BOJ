#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    //prepre=f_0, pre==f_1, result=f_2
    long long pre=1, prepre=0;
    if(n==1) cout<<1<<endl;
    else{
        long long result=pre + prepre;
        for(int i=2;i<=n;i++){
            result = pre + prepre;
            prepre = pre;
            pre = result;
        }
        cout<<result<<endl;
    }
}