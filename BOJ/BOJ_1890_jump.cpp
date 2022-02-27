#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(auto i = a; i < b; ++i)
#define REP(i, a, b) for(auto i = a; i <= b; ++i)
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define INF 987654321

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
int board[100][100];
ll cache[100][100];


ll jump(int y, int x){
    if(y >= n || x >= n) return 0;
    if((y == n - 1) && (x == n - 1)) return 1;
    
    ll& ret = cache[y][x];
    if(ret != -1) return ret;
    
    int jump_size = board[y][x];
    if(jump_size == 0) return 0;
    return ret = jump(y + jump_size, x) + jump(y, x + jump_size);
}

int main(){
    FAST;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;
    rep(i, 0, n) rep(j, 0, n) cin >> board[i][j];
    memset(cache, -1, sizeof(cache));
    cout << jump(0, 0);

    return 0;
}
