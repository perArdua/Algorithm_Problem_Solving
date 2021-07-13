#include <bits/stdc++.h>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>
#define pb push_back
#define INF 987654321

using namespace std;

char board[5][5];
int cache[5][5][10];
string words;

const int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool inRange(int y, int x){
    return (y >= 0 && y < 5) && (x >= 0 && x < 5);
}

int check(const int y, const int x, const string& org_string, int idx){
    if(!inRange(y, x)) return 0;

    int& ret = cache[y][x][idx];
    if(ret != -1) return ret;

    if(board[y][x] != org_string[idx]) return 0;
    if(idx == org_string.size() - 1) return 1;
    for(int dir = 0; dir < 8; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ret = check(ny, nx, org_string, idx + 1)){
            return ret;
        }
    }
    return 0;
}

int main(){
    FAST;
    int n, t;
    cin >> t;
    while(t--){
        rep(i, 0, 5){
            rep(j, 0, 5){
                cin >> board[i][j];
            }
        }
        cin >> n;
        rep(i, 0, n){
            cin >> words;
            bool flag = false;
            memset(cache, -1, sizeof(cache));

            rep(j, 0, 5){
                rep(k, 0, 5){
                    if(check(j, k, words, 0)){
                        flag = true;
                        break;
                    }
                }
            }
            if(flag){
                cout << words << ' ' << "YES" << endl;
            }else{
                cout << words << ' ' << "NO" << endl;
            }
        }
    }
    return 0;
} 