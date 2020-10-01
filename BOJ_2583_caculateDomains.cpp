#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int row, col, num_rec;

int dfs(const vector<vector<int> >& m, vector<vector<bool> >& c, const int y, const int x){
    int ret = 1;
    c[y][x] = true;

    for(int dir = 0; dir < 4; ++dir){
        const int ny = y + dy[dir];
        const int nx = x + dx[dir];
        if((ny >= 0 && ny < row) && (nx >= 0 && nx < col)){
            if(!m[ny][nx] && !c[ny][nx]) ret += dfs(m, c, ny, nx);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> row >> col >> num_rec;
    vector<vector<int> > map(row, vector<int>(col, 0));
    vector<vector<bool> > check(row, vector<bool>(col, false));
    vector<int> ans;
    while(num_rec--){
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        for(int cur_x = lx; cur_x < rx; ++cur_x){
            for(int cur_y = ly; cur_y < ry; ++cur_y){
                map[cur_y][cur_x] = 1;
            }
        }
    }

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(!map[i][j] && !check[i][j]){
                ans.push_back(dfs(map, check, i, j));
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}