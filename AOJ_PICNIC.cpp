#include <iostream>
#include <cstring>
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

bool areFriends[10][10];
int n, m;

int recursion(bool taken[10]){
    int first = -1;
    rep(i, 0, n){
        if(!taken[i]){
            first = i;
            break;
        }
    }
    if(first == -1) return 1;
    int ret = 0;
        rep(next, first + 1, n){
            if(!taken[next] && areFriends[first][next]){
                taken[next] = taken[first] = true;
                ret += recursion(taken);
                taken[next] = taken[first] = false;
            }
        }

    return ret;
}

int main(){
    FAST;
    int t;
    cin >> t;
    REP(tc, 1, t){
        bool check[10];
        cin >> n >> m;
        memset(areFriends, false, sizeof(areFriends));
        memset(check, false, sizeof(check));
        rep(i, 0, m){
            int u, v;
            cin >> u >> v;
            areFriends[u][v] = areFriends[v][u] = true;
        }
        int res = recursion(check);
        cout << res << endl;
    }
    return 0;
} 