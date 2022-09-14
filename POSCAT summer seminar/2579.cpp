// #include <iostream>
// #include <vector>
// using namespace std;

// int down_stairs(int stair, vector<int> scores, int cnt); //cnt는 연속된 칸을 밟은 횟수, 오직 1번만 연속된 칸을 밟을 수 있음
// int maxScores[300];

// int main(){
//     int N;
//     vector<int> scores;

//     for(int j=0;j<300;j++) maxScores[j] = -1;

//     cin>>N;
//     scores.push_back(0);
//     for(int i=0;i<N;i++){
//         int n;
//         cin>>n;
//         scores.push_back(n);
//     }
//     cout<<down_stairs(N, scores, 0)<<endl;
// }

// int down_stairs(int stair, vector<int> scores, int cnt){
//     if(stair==0) return 0;
//     else if(stair == 1) return scores[1];
//     else if(maxScores[stair] != -1) return maxScores[stair];
//     else{
//         if(cnt == 0) maxScores[stair] = max(down_stairs(stair-1,scores,1),down_stairs(stair-2,scores,0))+scores[stair];
//         else maxScores[stair] = down_stairs(stair-2,scores,0)+scores[stair];
//         return maxScores[stair];
//     }
// }

// 위 코드는 top-down 방식으로 문제를 해결하려 했으나 그 방식으로는 구현이 안됨.

#include <iostream>
#include <vector>
using namespace std;
int maxScore[301] = {0, };
vector<int> v;

int main(){
    int n, data;
    cin>>n;

    v.push_back(0);
    for(int i = 0; i < n; i++){
        cin>>data;
        v.push_back(data);
    }

    maxScore[1] = v[1];
    maxScore[2] = v[1] + v[2];
    maxScore[3] = max(v[1], v[2]) + v[3];

    for(int i = 4; i <= n; i++){
        maxScore[i] = max(maxScore[i-3]+v[i-1]+v[i], maxScore[i-2]+v[i]);
    }

    cout<<maxScore[n]<<endl;
}