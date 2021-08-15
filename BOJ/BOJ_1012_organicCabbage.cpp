#include <iostream>
#include <cstring>
#define endl "\n"

using namespace std;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int map[50][50];
bool visited[50][50];

inline bool inRange(const int y,const int x, const int row, const int col){
    return (y >= 0 && y < row) && (x >= 0 && x < col); 
}

void dfs(const int y, const int x, const int row, const int col){
    visited[y][x] = true;
    for(int dir = 0; dir < 4; ++dir){
        const int ny = y + dy[dir];
        const int nx = x + dx[dir];
        if(!inRange(ny, nx, row, col)) continue;
        if(!map[ny][nx]) continue;
        if(visited[ny][nx]) continue;
        dfs(ny, nx, row, col);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int col, row, cnt_cabbage;
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        cin >> col >> row >> cnt_cabbage;
        while(cnt_cabbage--){
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }
        int res = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(map[i][j] && !visited[i][j]){
                    dfs(i, j, row, col);
                    ++res;
                }
            }
        }
        cout << res << endl;;
    }
    return 0;
}
