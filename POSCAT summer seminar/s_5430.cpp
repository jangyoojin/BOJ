#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

deque<int> split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;
    deque<int> result;

    while(getline(iss,buffer,Delimiter)){
        result.push_back(stoi(buffer));
    }
    return result;
}


int main(){
    int T, n;
    cin>>T;
    for(int i = 0; i<T;i++){
        bool is_front = true, is_error = false;
        string func, numbers;
        deque<int> q;
        cin>>func;
        cin>>n;
        cin>>numbers;
        numbers.erase(0,1);
        numbers.pop_back();
        q = split(numbers,',');      
        for(char c: func){
            if(c == 'R') is_front = !is_front;
            else{
                if(q.empty()) {is_error = true; break;}
                else if(is_front) q.pop_front();
                else q.pop_back();
            }
        }
        string output;
        if(is_error) output = "error";
        else if(is_front){
            output = "[";
            for(int i: q) output += to_string(i) +",";
            if(output.back() == ',') output.pop_back();
            output += "]";
        }
        else{
            output = "[";
            for(int i = q.size()-1; i>=0; i--){
                output += to_string(q[i]) + ",";
            }
            if(output.back() == ',') output.pop_back();
            output += "]";
        }
        cout<<output<<"\n";
    }
    


}