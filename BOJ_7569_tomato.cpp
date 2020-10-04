#include <iostream>
#include <queue>
#define endl "\n"

using namespace std;
class Point{
    int height, row, col;
    public:
        Point(int _h, int _r, int _c) : height(_h), row(_r), col(_c) {}
        int getRow() const{
            return row;
        }
        int getCol() const{
            return col;
        }
        int getHeight() const{
            return height;
        }
};

const int movement[][3] = { {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}, {1, 0, 0}, {-1, 0, 0} }; // z, y, x


int boxes[100][100][100];
int row, col, height;

inline int max(int a, int b){
    return a > b ? a : b;
}

int findAns(int height, int row, int col){
    int ret = -1;

    for(int h = 0; h < height; ++h){
        for(int r = 0; r < row; ++r){
            for(int c = 0; c < col; ++c){
                if(boxes[h][r][c] == 0){
                    return -1;
                }
                ret = max(ret, boxes[h][r][c]);
            }
        }
    }
    return ret;
}

void findStartPoint(queue<Point>& q){
    int cnt = 0;
    for(int h = 0; h < height; ++h){
        for(int r = 0; r < row; ++r){
            for(int c = 0; c < col; ++c){
                if(boxes[h][r][c] == 1){
                    q.push(Point(h, r, c));
                }else if(boxes[h][r][c] == 0){
                    ++cnt;
                }
            }
        }
    }

    if(cnt == 0){
        cout << cnt;
        exit(0);
    }
}

bool inRange(int z, int y, int x){
    return ((z >= 0 && z < height) && (y >= 0 && y < row) && (x >= 0 && x < col));
}

void dfs(){
    queue<Point> q;
    findStartPoint(q);
    while(!q.empty()){
        Point point = q.front(); q.pop();
        int z = point.getHeight();
        int y = point.getRow();
        int x = point.getCol();
        for(int dir = 0; dir < 6; ++dir){
            int nz = z + movement[dir][0];
            int ny = y + movement[dir][1];
            int nx = x + movement[dir][2];

            if(!inRange(nz, ny, nx)) continue;
            if(boxes[nz][ny][nx] != 0) continue;

            boxes[nz][ny][nx] = boxes[z][y][x] + 1;
            q.push(Point(nz, ny, nx));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> col >> row >> height;
    for(int h = 0; h < height; ++h){
        for(int r = 0; r < row; ++r){
            for(int c = 0; c < col; ++c){
                cin >> boxes[h][r][c];
            }
        }
    }

    dfs();
    int res = findAns(height, row, col);
    if(res == -1){
        cout << res;
        return 0;
    }else{
        cout << res - 1;
    }

    return 0;
}