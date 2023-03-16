#include <iostream>
#include <deque>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N, result = 0;
    deque<int> A;
    map<int, int> is_sum_exist;
    cin >> N;
    for(int i =0; i<N; i++) {
        int tmp;
        cin>>tmp;
        A.push_back(tmp);
    }
    // for(int i = 0; i<N-1; i++) {
    //     for(int j = i+1; j<N; j++) {
    //         is_sum_exist[A[i]+A[j]] = 1;
    //     }
    // }
    // for(int i =0; i<N;i++){
    //     if(is_sum_exist[A[i]] == 1) {
    //         result++;
    //     }
    // }
    sort(A.begin(), A.end());
    //0번째, n-1번째를 위한 for문, j,k가 같아지면 종료

    //그 외 경우
    for(int i = 1; i<N-1; i++) {
        int j = 0, k = N-1;
        while(j != i || k != i) {
            if(A[j]+A[k] > A[i]) k--;
            else if(A[j]+A[k] < A[i]) j++;
            else {
                result++;
                break;
            }
        }
    }
    cout<<result<<endl;

}