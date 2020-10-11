#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#define endl "\n"
#define space '.'
#define wall '#'
#define startPoint 'J'
#define fire 'F'
using namespace std;

const int dy[] = {-1, 1 ,0 ,0};
const int dx[] = {0, 0, -1, 1};

int row, col;
vector<string> map(1000);
vector<vector<bool> > mapCheck(1000, vector<bool>(1000, 0));
vector<vector<bool> > fireCheck(1000, vector<bool>(1000, 0));

struct Info{
    int y, x, time;
    Info(int y, int x) : y(y), x(x), time(0) {}
    Info(int y, int x, int t) : y(y), x(x), time(t) {}
};

inline bool inRange(int ny, int nx){
    return ((ny >= 0 && ny < row) && (nx >= 0 && nx < col));
}

Info findStartPoint(){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(map[i][j] == startPoint){
                return Info(i, j); 
            }
        }
    }
}

void findInitFire(queue<Info>& q){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(map[i][j] == fire){
                q.push(Info(i, j, -1));
                fireCheck[i][j] = true;
            }
        }
    }
}

int bfs(){
    queue<Info> q;
    queue<Info> firePos;
    q.push(findStartPoint());
    mapCheck[q.front().y][q.front().x] = q.front().time;
    findInitFire(firePos);
    while(!q.empty()){ 
        queue<Info> tmp;
        while(!firePos.empty()){
            Info curFire = firePos.front(); firePos.pop();
            int y = curFire.y, x = curFire.x;
            for(int d = 0; d < 4; ++d){
                int ny = y + dy[d];
                int nx = x + dx[d];
                if(!inRange(ny, nx)) continue;
                if(fireCheck[ny][nx]) continue;
                if(map[ny][nx] != wall){
                    map[ny][nx] = fire;
                    fireCheck[ny][nx] = true;
                    tmp.push(Info(ny, nx, -1));
                }
            }
        }
        firePos = move(tmp);

        while(!q.empty()){
            Info curPos = q.front(); q.pop();
            for(int d = 0; d < 4; ++d){
                int ny = curPos.y + dy[d];
                int nx = curPos.x + dx[d];
                if(!inRange(ny, nx)) return curPos.time + 1;
                if(mapCheck[ny][nx]) continue;
                if(map[ny][nx] == space){
                    map[ny][nx] = startPoint;
                    map[curPos.y][curPos.x] = space;
                    mapCheck[ny][nx] = true;
                    tmp.push(Info(ny, nx, curPos.time + 1));
                }
            }
        }
        q = move(tmp);

        
    }
    return -1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> row >> col;

    for(int i = 0; i < row; ++i){
        string tmp;
        cin >> tmp;
        map[i] = tmp;
    }

    int res = bfs();

    if(res == -1){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << res << endl;
    }

    return 0;
}