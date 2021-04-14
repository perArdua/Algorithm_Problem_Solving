#include <iostream>
#include <vector>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>
#define INF 987654321

using namespace std;

int n, m;
vector<vector<int> > adj;
vector<int> in;
vector<bool> visited;

void input(){
    cin >> n >> m;
    adj = vector<vector<int> > (n);
    in = vector<int>(n, -1);

    rep(i, 0, m){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

bool dfs(int here){
    if(visited[here]) return false;
    visited[here] = true;
    
    for(auto there : adj[here]){
        if(in[there] == -1 || dfs(in[there])){
            in[there] = here;
            return true;
        }
    }
    return false;
};

int bipartiteMatch(){
    int ret = 0;
    rep(i, 0, n){
        visited = vector<bool>(n, false);
        if(dfs(i)) ++ret;
    }
    return ret;
}

int main(){
    FAST;
    int t;
    cin >> t;
    while(t--){
        input();
        cout << bipartiteMatch() << endl;
    }
    return 0;
} 