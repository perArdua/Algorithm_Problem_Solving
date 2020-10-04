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

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

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

void dfs(){
    queue<Point> q;
    findStartPoint(q);
    while(!q.empty()){
        Point point = q.front(); q.pop();
        int y = point.getRow();
        int x = point.getCol();
        int z = point.getHeight();
        for(int dir = 0; dir < 4; ++dir){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(!((ny >= 0 && ny < row) && (nx >= 0 && nx < col))) continue;
            if(boxes[z][ny][nx] != 0) continue;
            boxes[z][ny][nx] = boxes[z][y][x] + 1;
            q.push(Point(z, ny, nx));
        }
        
        if(z - 1 >= 0 && z - 1 < height){
            if(boxes[z-1][y][x] == 0){
                boxes[z-1][y][x] = boxes[z][y][x] + 1;
                q.push(Point(z - 1, y, x));
            }
        }

        if(z + 1 >= 0 && z + 1 < height){
            if(boxes[z+1][y][x] == 0){
                boxes[z+1][y][x] = boxes[z][y][x] + 1;
                q.push(Point(z + 1, y, x));
            }
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
        cout << -1;
        return 0;
    }else{
        cout << res - 1;
    }

    return 0;
}
// ?