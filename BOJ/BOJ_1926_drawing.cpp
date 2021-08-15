#include <iostream>

#define endl "\n"

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int row, col;
int map[500][500];
bool check[500][500];

inline int max(int a, int b){
    return a > b ? a : b;
}

int dfs(const int y, const int x){
    int ret = 1;
    check[y][x] = true;

    for(int dir = 0; dir < 4; ++dir){
        const int ny = y + dy[dir];
        const int nx = x + dx[dir];
        if((ny >= 0 && ny < row) && (nx >= 0 && nx < col)){
            if(map[ny][nx] && !check[ny][nx]) ret += dfs(ny, nx);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> row >> col;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            cin >> map[i][j];
        }
    }
    int res = 0, cnt = 0;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(map[i][j] && !check[i][j]){
                ++cnt;
                res = max(res, dfs(i, j));
            }
        }
    }
    cout << cnt << endl;
    cout << res << endl;
    return 0;
}