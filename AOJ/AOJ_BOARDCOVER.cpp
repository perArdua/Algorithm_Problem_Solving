#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>
#define pb push_back
#define INF 987654321

using namespace std;

int board[20][20];
int r, c;

const int coverType[4][3][2] = {
    { {0, 0}, {1, 0}, {0, 1} },
    { {0, 0}, {0, 1}, {1, 1} },
    { {0, 0}, {1, 0}, {1, 1} },
    { {0, 0}, {1, 0}, {1, -1} }
};

bool inRange(int y, int x){
    return (y >= 0 && y < r) && (x >= 0 && x < c);
}

bool setBlock(int y, int x, int type, int delta){
    bool flag = true;
    rep(dir, 0, 3){
        const int ny = y + coverType[type][dir][0];
        const int nx = x + coverType[type][dir][1];
        if(!inRange(ny, nx)){
            flag = false;
        }else if((board[ny][nx] += delta) > 1){
            flag = false;
        }
    }
    return flag;
}

int cover(){
    int y = -1, x = -1;
    rep(i, 0, r){
        rep(j, 0, c){
            if(board[i][j] == 0){
                y = i;
                x = j;
                break;
            }
        }
        if(y != -1) break;
    }
    if(y == -1) return 1;
    int ret = 0;
    rep(type, 0, 4){
        if(setBlock(y, x, type, 1)){
            ret += cover();
        }
        setBlock(y, x, type, -1);
    }
    return ret;
}

int main(){
    FAST;
    int t;
    cin >> t;
    rep(tc, 0, t){
        char tmp;
        int cnt = 0, res = 0;
        cin >> r >> c;
        memset(board, 0, sizeof(board));
        rep(i, 0, r){
            rep(j, 0, c){
                cin >> tmp;
                if(tmp == '#'){
                    ++cnt;
                    board[i][j] = 1;
                }
            }
        }
        res = 0;
        if((r * c - cnt) % 3 != 0){
            cout << res << endl;
            continue;
        }
        res = cover();
        cout << res << endl;
    }
    return 0;
} 
