#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

const int dy[] = {-1, 1 ,0 ,0};
const int dx[] = {0, 0, -1, 1};

struct Point{
    int y, x;
    Point(int y, int x) : y{y}, x{x} {}
};

int row, col;
char map[1500][1500];
bool check[1500][1500];
vector<Point> swanPos;
queue<Point> waterQ;
queue<Point> g;

inline bool inRange(int y, int x){
    return ((y >= 0 && y < row) && (x >= 0 && x < col));
}

void input(){
    cin >> row >> col;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            cin >> map[i][j];
            if(map[i][j] == 'L'){
                swanPos.push_back(Point(i, j));
                waterQ.push(Point(i, j));
            }else if(map[i][j] == '.'){
                waterQ.push(Point(i, j));
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
            if(map[ny][nx] == 'X'){
                map[ny][nx] = '.';
                tmp.push(Point(ny, nx));
            }
        }
    }
    waterQ = move(tmp);
}

bool isSameSection(){
    queue<Point> nextStep;
    while(!g.empty()){
        Point tmp = g.front(); g.pop();
        int y = tmp.y, x = tmp.x;
        for(int dir = 0; dir < 4; ++dir){
            const int ny = y + dy[dir];
            const int nx = x + dx[dir];
            
            if((ny == swanPos.back().y) && (nx == swanPos.back().x)){
                return true;
            }
            
            if(!inRange(ny, nx) || check[ny][nx]) continue;
            if(map[ny][nx] == 'X'){
                nextStep.push(Point(ny, nx));
                check[ny][nx] = true;
                continue;
            }else if(map[ny][nx] == '.'){
                g.push(Point(ny, nx));
                check[ny][nx] = true;
            }
            
        }
    }
    g = move(nextStep);

    return false;
}

int dfsSolve(){
    int retDays = 0;
    while(true){
        if(isSameSection()){
            break;
        }
        else{
            melting();
            ++retDays;
        }
    }
    return retDays;
}

void initStart(){
    g.push(swanPos[0]);
    check[swanPos[0].y][swanPos[0].x] = true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    initStart();
    cout << dfsSolve() << endl;
    return 0;
}