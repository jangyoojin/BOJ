#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
bool flag = false;
int board[9][9] = {0,};
vector <pair<int,int>> blank;

bool check(int x, int y) {
    int a = x % 3;
    int b = y % 3;


    for(int i =0; i<9; i++){
        //가로 줄 같은 수 있는지 확인
        if(board[x][i] == board[x][y] && i != y) return false;
        //세로 줄에 같은 수 있는지 확인
        if(board[i][y] == board[x][y] && i != x) return false;
    }

    //3*3 칸 안에 같은 수 있는지 확인
    for(int i = x - a; i < x-a+3; i++) {
        for(int j = y-b; j < y-b+3; j++) {
            if(i == x && j == y) continue;
            if(board[i][j] == board[x][y]) return false;
        }
    }
    return true;
}

void func(int n){
    if(n == cnt) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        flag = true;
        return;
    }
    int x = blank[n].first;
    int y = blank[n].second;

    for(int i = 1; i <= 9; i++){
        board[x][y] = i;
        if(check(x, y)){
            func(n+1);
        }
    }
    board[x][y] = 0;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0){
                blank.push_back(make_pair(i,j));
                cnt++;
            }
        }
    }
    func(0);
}