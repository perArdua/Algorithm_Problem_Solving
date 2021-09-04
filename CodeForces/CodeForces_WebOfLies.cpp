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

const int MAX_NUMBER = 2 * 1e5 + 1;

int main(){
    FAST;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    // If one node has at least one edge then the node or the other must be killed during process.
    // The killed node has lowest number
    int n, m, u, v, q, t, killed = 0;
    int noble[MAX_NUMBER] = {0,};
    cin >> n >> m;
    rep(i, 0, m){
        cin >> u >> v;
        if(u > v) swap(u, v);
        ++noble[u];
        if(noble[u] == 1) ++killed;
    }
    cin >> q;
    while(q--){
        cin >> t;
        if(t == 3){
            cout << n - killed << endl;
        }else{
            cin >> u >> v;
            if(u > v) swap(u, v);
            if(t == 1){
                ++noble[u];
                if(noble[u] == 1) ++killed;
            }else{
                --noble[u];
                if(!noble[u]) --killed;
            }
        }
    }
#ifndef ONLINE_JUDGE
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}