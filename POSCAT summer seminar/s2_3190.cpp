#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <map>
using namespace std;

// (0,0) (1,0) (2,0) (3,0)
// (0,1) (1,1) (2,1) (3,1)
// (0,2) (1,2) (2,2) (3,2)
// (0,3) (1,3) (2,3) (3,3)
int board[101][101] = {0};

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int N, K, L, sec=0, flag=0, direction = 1;

struct Snake {int x,y;};

deque <Snake> snake;
map<int, char> m;

int main(){
    snake.push_back({1,1});
    cin >> N >> K;

    while(K--){
        int x,y;
        cin >> x >> y;
        board[x][y] = 1;
    }
    cin >> L;
    while(L--){
        int x;
        char dir;
        cin >> x >> dir;
        m[x] = dir;
    }

    while(1){
        sec++;
        int x = snake.front().x;
        int y = snake.front().y;
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        for(auto &el : snake) {
            if(el.x == nx && el.y == ny) {
                flag = 1; break;
            }
        }
        if(1 > nx || nx > N || 1 > ny || ny > N || flag){flag = 1; break;}
        snake.push_front({nx,ny});
        if(!board[nx][ny]) { snake.pop_back(); }
        else board[nx][ny] = 0;
        if(m[sec] == 'D') direction = (direction + 1) %4;
        else if(m[sec] == 'L') direction = (direction + 3) %4;
    }

    cout << sec << "\n";
}