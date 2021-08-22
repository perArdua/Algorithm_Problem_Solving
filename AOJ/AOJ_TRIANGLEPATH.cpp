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
typedef long long ll;
typedef unsigned long long ull;

int n;
int cache[100][100];
int triangle[100][100];

int path(int y = 0, int x = 0){
    if(y == n - 1) return triangle[y][x];
    
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

int main(){
    FAST;
//     freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    rep(tc, 0, t){
        memset(cache, -1, sizeof(cache));
        memset(triangle, -1, sizeof(triangle));
        cin >> n;
        rep(i, 0, n){
            rep(j, 0, i + 1){
                cin >> triangle[i][j];
            }
        }
        cout << path() << endl;
    }
    return 0;
}
