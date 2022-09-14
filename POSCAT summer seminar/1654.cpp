#include <iostream>
#include <vector>
using namespace std;

int main(){
    unsigned int K,N, maxlen=0;
    int sum=0;
    vector<int> v;
    cin>>K>>N;
    for(int i=0;i<K;i++){
        unsigned int n;
        cin>>n;
        //sum += n;
        maxlen = max(maxlen,n);
        v.push_back(n);
    }
    //가능한 가장 긴 길이
    //maxlen = int(sum/N); 
    unsigned int end = maxlen;
    unsigned int start = 1;
    unsigned int resultlen=0;
    //이진 탐색
    while(start<=end){
        unsigned int mid = int((start+end)/2);
        int lenNum = 0;
        for(int i=0;i<K;i++){
            lenNum +=v[i]/mid;
        }
        if(lenNum>=N) {
            resultlen = max(mid,resultlen);
            start = mid+1;
        }
        else end = mid-1;
    }
    printf("%d",resultlen);
}
