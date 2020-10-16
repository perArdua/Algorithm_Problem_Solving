#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#define endl "\n"
#define water 0
#define ice 1
#define swan 2
using namespace std;

const int dy[] = {-1, 1 ,0 ,0};
const int dx[] = {0, 0, -1, 1};

struct Point{
    int y, x;
    Point(int y, int x) : y{y}, x{x} {}
};

int row, col;
int map[1500][1500];
vector<Point> swanPos;
queue<Point> waterQ;

inline bool inRange(int y, int x){
    return ((y >= 0 && y < row) && (x >= 0 && x < col));
}

void input(){
    for(int i = 0; i < row; ++i){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < tmp.size(); ++j){
            switch (tmp[j]){
                case '.':
                    map[i][j] = water;
                    break;
                case 'X':
                    map[i][j] = ice;
                    break;
                case 'L':
                    map[i][j] = swan;
                    swanPos.push_back(Point(i, j));
                    break;
                default:
                    cout << "wrong input" << endl;
                    exit(0);
                    break;
            }
        }
    }
}

void findFirstAdjacent(){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(map[i][j] == water){
                for(int dir = 0; dir < 4; ++dir){
                    const int ny = i + dy[dir];
                    const int nx = j + dx[dir];
                    if(map[ny][nx] == ice){
                        waterQ.push(Point(i, j));
                        break;
                    }
                }
            }
        }
    }
}

void melting(){
    queue<Point> tmp;
    while(!waterQ.empty()){
        Point po = waterQ.front(); waterQ.pop();
        int y = po.y, x = po.x;
        for(int dir = 0; dir < 4; ++dir){
            const int ny = y + dy[dir];
            const int nx = x + dx[dir];
            if(!inRange(ny, nx)) continue;
            if(map[ny][nx] == ice){
                map[ny][nx] = water;
                tmp.push(Point(ny, nx));
            }
        }
    }
    waterQ = move(tmp);
}

bool isSameSection(){
    bool check[1500][1500];
    memset(check, 0, sizeof(check));
    queue<Point> g;
    g.push(swanPos[0]);
    while(!g.empty()){
        Point tmp = g.front(); g.pop();
        int y = tmp.y, x = tmp.x;
        for(int dir = 0; dir < 4; ++dir){
            const int ny = y + dir[dy];
            const int nx = x + dir[dx];
            if(!inRange(ny, nx)) continue;
            if(map[ny][nx] == ice) continue;
            if(check[ny][nx]) continue;

            if(map[ny][nx] == swan){
                return true;
            }else{
                g.push(Point(ny, nx));
                check[ny][nx] = true;
            }
        }
    }
    return false;
}

int dfsSolve(){
    int retDays = 0;
    findFirstAdjacent();
    while(true){
        if(isSameSection()) {break;}
        else{
            melting();
            ++retDays;
        }
    }
    return retDays;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> row >> col;
    input();
    cout << dfsSolve() << endl;
    return 0;
}