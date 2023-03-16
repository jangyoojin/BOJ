#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <vector>
#include <set>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}

int main() {
    int N, start, end, number_com = 0, time = 0;
    deque<pair<int,int>> times;
    deque<int> number_use(100005,0);
    priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int,int>>> using_com;
    priority_queue<int, vector<int>, greater<>> empty_com;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> start >> end;
        times.push_back(make_pair(start, end));
    }
    sort(times.begin(),times.end(), compare);

    int current_com;
    for(int i = 0; i < N; i++) {
        //현재 시작 시간보다 이전에 끝난 애들 빼주기
        while(!using_com.empty()) {
            if(using_com.top().first < times[i].first) {
                empty_com.push(using_com.top().second);
                number_use[using_com.top().second]++;
                using_com.pop();
            }
            else break;
        }
        if(empty_com.empty()) current_com = number_com++;
        else {
            current_com = empty_com.top();
            empty_com.pop();
        }

        using_com.push(make_pair(times[i].second, current_com));
    }

    while(!using_com.empty()) {
        number_use[using_com.top().second]++;
        using_com.pop();
    }

    cout<<number_com<<'\n';
    for(int i =0;i < number_com; i++) {
        cout<<number_use[i]<<" ";
    }
    cout<<'\n';
}