#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    stack<int> s;
    vector<int> v;
    int n, temp;
    vector<int> OBN(1000002,-1);
    cin>>n;
    for(int i = 0; i< n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    for(int i = 0; i<n; i++) {
        if(s.empty()) s.push(i);
        // else if(v[s.top()] >= v[i]) {
        //     s.push(i);
        // }
        else{
            while(!s.empty() && v[s.top()] < v[i]){
                int idx = s.top();
                s.pop();
                OBN[idx] = v[i];
            }
            s.push(i);
        }
    }

    for(int i =0; i<n; i++){
        cout<<OBN[i]<<" ";
    }
    
    return 0;
}
