#include <iostream>
#include <string>
#include <cstring>
#include <queue>

#define endl "\n"

using namespace std;

const int dy[] = {-1, 1 ,0 ,0};
const int dx[] = {0, 0, -1, 1};

struct Info{
    int y, x;
    bool isBreak;
    Info(int y, int x, bool isBreak = false) : y{y}, x{x}, isBreak{isBreak} {}
};

int row, col;
int map[1000][1000];
int dist[1000][1000][2];

void input(){
    for(int i = 0; i < row; ++i){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < tmp.size(); ++j){
            map[i][j] = tmp[j] - '0';
        }
    }
}

inline int min(int a, int b){
    if(a > b) return b;
    return a;
}

inline bool inRange(int y, int x){
    return ((y >= 0 && y < row) && (x >= 0 && x < col));
}

int bfs(){
    queue<Info> q;
    q.push(Info{0, 0});
    dist[0][0][0] = 1;
    while(!q.empty()){
        Info cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; ++dir){
            const int ny = cur.y + dy[dir];
            const int nx = cur.x + dx[dir];

            if(!inRange(ny, nx)) continue;

            if(map[ny][nx] == 1 && !cur.isBreak){
                dist[ny][nx][!cur.isBreak] = dist[cur.y][cur.x][cur.isBreak] + 1;
                q.push(Info(ny, nx, true));
            }else if(map[ny][nx] == 0 && dist[ny][nx][cur.isBreak] == 0){
                dist[ny][nx][cur.isBreak] = dist[cur.y][cur.x][cur.isBreak] + 1;
                q.push(Info(ny, nx, cur.isBreak));
            }
        }
        if(cur.y == row - 1 && cur.x == col - 1){
            return dist[cur.y][cur.x][cur.isBreak];
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> row >> col;
    input();
    memset(dist, 0, sizeof(dist));
    cout << bfs() << endl;
    return 0;
}