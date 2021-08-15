#include <iostream>
#include <algorithm>
#define endl "\n"

using namespace std;
const int REMOVE_TIME = 2;
const int PUT_TIME = 1;
const int INF = 987654321;
int n, m, b;
int map[500][500];

inline int abs(int a){
    if(a < 0) return a *(-1);
    return a;
}

int bruteForce(int height){
    int ret_time = 0;
    int tmp_block = b;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int cal_block = map[i][j] - height;
            if(cal_block > 0){
                ret_time += cal_block * REMOVE_TIME;
                tmp_block += cal_block;
            }else if(cal_block < 0){
                ret_time += abs(cal_block) * PUT_TIME;
                tmp_block -= abs(cal_block);
            }
        }
    }
    return tmp_block < 0 ? INF : ret_time;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> b;
    int min_height = 987654321;
    int max_height = -1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> map[i][j];
        }
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            min_height = min(min_height, map[i][j]);
            max_height = max(max_height, map[i][j]);
        }
    }
    int h, t = INF;
    for(int i = max_height; i >= min_height; --i){
        int res = bruteForce(i);
        if(t > res){
            t = res;
            h = i;
        }
    }

    cout << t << " " << h << endl;
    return 0;
}