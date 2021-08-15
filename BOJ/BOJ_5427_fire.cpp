#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#define endl "\n"
#define space '.'
#define wall '#'
#define startPoint '@'
#define fire '*'
using namespace std;

const int dy[] = {-1, 1 ,0 ,0};
const int dx[] = {0, 0, -1, 1};

struct Info{
    int y, x, time;
    Info(int y, int x) : y(y), x(x), time(0) {}
    Info(int y, int x, int t) : y(y), x(x), time(t) {}
};

inline bool inRange(int ny, int nx, int r, int c){
    return ((ny >= 0 && ny < r) && (nx >= 0 && nx < c));
}

Info findStartPoint(vector<string>& m){
    for(int i = 0; i < m.size(); ++i){
        for(int j = 0; j < m[0].size(); ++j){
            if(m[i][j] == startPoint){
                return Info(i, j); 
            }
        }
    }
}

void findInitFire(const vector<string>& m, queue<Info>& q, vector<vector<bool> >& fc){
    for(int i = 0; i < m.size(); ++i){
        for(int j = 0; j < m[0].size(); ++j){
            if(m[i][j] == fire){
                q.push(Info(i, j, -1));
                fc[i][j] = true;
            }
        }
    }
}

int bfs(vector<string>& m, vector<vector<bool> >& c, vector<vector<bool> >& fc){
    queue<Info> q;
    queue<Info> firePos;
    int row = m.size(), col = m[0].size();
    q.push(findStartPoint(m));
    c[q.front().y][q.front().x] = q.front().time;
    findInitFire(m, firePos, fc);
    while(!q.empty()){ 
        queue<Info> tmp;
        while(!firePos.empty()){
            Info curFire = firePos.front(); firePos.pop();
            int y = curFire.y, x = curFire.x;
            for(int d = 0; d < 4; ++d){
                int ny = y + dy[d];
                int nx = x + dx[d];
                if(!inRange(ny, nx, row, col)) continue;
                if(fc[ny][nx]) continue;
                if(m[ny][nx] != wall){
                    m[ny][nx] = fire;
                    fc[ny][nx] = true;
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
                if(!inRange(ny, nx, row, col)) return curPos.time + 1;
                if(c[ny][nx]) continue;
                if(m[ny][nx] == space){
                    m[ny][nx] = startPoint;
                    m[curPos.y][curPos.x] = space;
                    c[ny][nx] = true;
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
    int t;
    cin >> t;
    while(t--){
        int row, col;
        cin >> col >> row;
        vector<string> map(row);
        vector<vector<bool> > mapCheck(row, vector<bool>(col, 0));
        vector<vector<bool> > fireCheck(row, vector<bool>(col, 0));

        for(int i = 0; i < row; ++i){
            string tmp;
            cin >> tmp;
            map[i] = tmp;
        }

        int res = bfs(map, mapCheck, fireCheck);
        if(res == -1){
            cout << "IMPOSSIBLE" << endl;
        }else{
            cout << res << endl;
        }
    }

    return 0;
}