#include <iostream>
#include <cstring>
#include <vector>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>

using namespace std;
int n, m;
vector<vector<int> > adj;
vector<bool> visited;
vector<int> shed;

void input(){
    cin >> n >> m;
    adj.resize(n);
    shed = vector<int>(m, -1);
    rep(i, 0, n){
        int tmp;
        cin >> tmp;
        rep(j, 0, tmp){
            int shed_number;
            cin >> shed_number;
            adj[i].push_back(--shed_number);
        }
    }
}

bool dfs(int here){
    if(visited[here]) return false;
    visited[here] = true;

    rep(i, 0, adj[here].size()){
        int there = adj[here][i];
        if(shed[there] == -1 || dfs(shed[there])){
            shed[there] = here;
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
    input();
    cout << bipartiteMatch() << endl;
    return 0;
}