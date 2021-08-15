#include <iostream>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

int n, m;
int parent[500000];
int set_rank[500000];

int find(int u){
    return parent[u] == u ? u : find(parent[u]);
}

bool merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return false;
    if(set_rank[u] > set_rank[v]) swap(u, v);
    parent[u] = v;
    if(set_rank[u] == set_rank[v]) ++set_rank[v];
    return true;
}

int main(){
    FAST;
    cin >> n >> m;
    rep(i, 0, n) parent[i] = i;
    int res = 0;
    rep(i, 0, m){
        int a, b;
        cin >> a >> b;
        if(merge(a, b) == false){
            res = i + 1;
            break;
        }
    }
    cout << res << endl;
    return 0;
}
// ?