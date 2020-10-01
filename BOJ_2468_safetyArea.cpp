#include <iostream>
#include <cstring>
#define endl "\n"

using namespace std;
const int INF = 987654321;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int area[100][100];
int is_sink_down[100][100]; // 1 = true, 0 = false and not visited, -1 = visited
int n;

void sink_area(const int h){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(area[i][j] <= h) is_sink_down[i][j] = 1;
        }
    }
}

void dfs(const int y, const int x){
    is_sink_down[y][x] = -1;

    for(int dir = 0; dir < 4; ++dir){
        const int ny = y + dy[dir];
        const int nx = x + dx[dir];
        if(!((ny >= 0 && ny < n) && (nx >= 0 && nx < n))) continue;
        if(is_sink_down[ny][nx] != 0) continue;
        dfs(ny, nx);
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int max_height = -1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> area[i][j];
            int& tmp = area[i][j];
            if(max_height < tmp) max_height = tmp;
        }
    }
    int res = 0;
    for(int h = 0; h <= max_height; ++h){
        sink_area(h);
        int tmp = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(is_sink_down[i][j] == 0){
                    dfs(i, j);
                    ++tmp;
                }
            }
        }
        if(res < tmp) res = tmp;
        memset(is_sink_down, 0, sizeof(is_sink_down));
    }
    cout << res << endl;
    return 0;
}