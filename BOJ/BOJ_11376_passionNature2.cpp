#include <iostream>
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
vector<int> work;
vector<bool> visited;

void input(){
    cin >> n >> m;
    adj.resize(n);
    work = vector<int>(m, -1);
    rep(i, 0, n){
        int temp;
        cin >> temp;
        rep(j, 0, temp){
            int number;
            cin >> number;
            adj[i].push_back(--number);
        }
    }
}

bool dfs(int here){
    if(visited[here]) return false;
    visited[here] = true;

    rep(i, 0, adj[here].size()){
        int there = adj[here][i];
        if(work[there] == -1 || dfs(work[there])){
            work[there] = here;
            return true;
        }
    }
    return false;
}

int bipartiteMatch(){
    int ret = 0;
    rep(i, 0, n){
        rep(j, 0, 2){
            visited = vector<bool>(n, false);
            if(dfs(i)) ++ret;
        }
    }
    return ret;
}

int main(){
    FAST;
    input();
    cout << bipartiteMatch();
    return 0;
} 
