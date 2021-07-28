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

int n, board[100][100];
int cache[100][100];

bool jump(int y, int x){
    if(y >= n || x >= n) return false;
    if((y == n - 1) && (x == n - 1)) return true;
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    int jumpSize = board[y][x];
    return ret = (jump(y + jumpSize, x) || jump(y, x + jumpSize));
}

int main(){
    FAST;
    int t;
    cin >> t;
    rep(tc, 0, t){
        cin >> n;
        memset(cache, -1, sizeof(cache));
        rep(i, 0, n) rep(j, 0, n) cin >> board[i][j];
        if(jump(0, 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}