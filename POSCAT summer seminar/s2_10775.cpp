#include <iostream>
#include <deque>

using namespace std;

//주어진 구간에서 비행기가 도킹할 수 있는 가장 큰 수를 도킹하면 됨
//근데 좋지 못한 경우 O(n^2)으로 모든 게이트를 탐색할 수 있음
//단순히 배열을 탐색하지 말고 다른 방법을 써야 함 -> union-find

deque<int> biggest_empty_gate;

int find(int index){
    if(biggest_empty_gate[index] == index)
        return index;
    biggest_empty_gate[index] = find(biggest_empty_gate[index]);
    return biggest_empty_gate[index];
}

int main() {
    int G, P, planes = 0, max_gate;
    cin >> G >> P;
    for(int i = 0; i < G+1; i++) 
        biggest_empty_gate.push_back(i);

    for(int i = 0; i < P; i++) {
        cin>>max_gate;
        int docking = find(max_gate);
        if(docking != 0) {
            biggest_empty_gate[docking] = biggest_empty_gate[docking-1];
            planes++;
        }
        else
            break;
    }
    cout << planes;

}