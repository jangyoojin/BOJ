#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

int main(){
    queue<int> q;
    string cmd;
    int N;

    cin>>N;
    getline(cin, cmd);
    for(int i =0;i<N;i++){
        getline(cin, cmd);
        istringstream ss(cmd);
        ss>>cmd;
        if(cmd=="push"){
            int n;
            ss>>n;
            q.push(n);
        }
        else if(cmd=="pop"){
            if(q.empty()) cout<<-1<<endl;
            else {
                cout<<q.front()<<endl;
                q.pop();}
        }
        else if(cmd=="size"){
            cout<<q.size()<<endl;
        }
        else if(cmd=="empty"){
            cout<<q.empty()<<endl;
        }
        else if(cmd=="front"){
            if(q.empty()) cout<<-1<<endl;
            else cout<<q.front()<<endl;
        }
        else if(cmd=="back"){
            if(q.empty()) cout<<-1<<endl;
            else cout<<q.back()<<endl;
        }
    }
}