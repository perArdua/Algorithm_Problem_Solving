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

int n, k, cnted;
vector<int> selected;
vector<int> visited_cnt;
vector<bool> visited;
vector<vector<int> > adj;

void input(){
    cin >> n >> k;
    adj.resize(n + 1);
    selected.resize(n + 1, -1);
    visited_cnt.resize(n + 1);
    rep(i, 0, k){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

bool dfs(int here){
    if(visited[here]) return false;
    visited[here] = true;

    for(auto there : adj[here]){
        if(selected[there] == -1 || dfs(selected[there])){
            selected[there] = here;
            return true;
        }
    }
    return false;
}

int bipartiteMatch(){
    int ret = 0;
    REP(i, 1, n){
        visited = vector<bool> (n + 1, false);
        if(dfs(i)) ++ret;
    }
    return ret;
}

int main(){
    FAST;
    input();
    cout << bipartiteMatch();
    return 0;
} 