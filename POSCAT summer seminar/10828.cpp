#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int main() {
    int N;
    stack<int> s;
    string cmd;

    cin>>N;
    getline(cin, cmd);
    for (int i=0;i<N; i++){
        getline(cin,  cmd);
        istringstream ss(cmd);
        ss>>cmd;
        if(cmd=="push"){
            int n;
            ss>>n;
            s.push(n);
        }
        else if(cmd=="pop"){
            if (s.empty()) cout<<-1<<endl;
            else{
                cout<<s.top()<<endl;
                s.pop();
            }
        }
        else if(cmd=="size"){
            cout<<s.size()<<endl;
        }
        else if(cmd=="empty"){
            cout<<s.empty()<<endl;
        }
        else if(cmd=="top"){
            if(s.empty()) cout<<-1<<endl;
            else{
            cout<<s.top()<<endl;}
        }
    }
}
