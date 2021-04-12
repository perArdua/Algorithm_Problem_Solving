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
vector<int> book;
vector<bool> visited;

void input(){
    cin >> n >> m;
    adj = vector<vector<int> >(m);
    book = vector<int>(n, -1);
    rep(i, 0, m){
        int from, to;
        cin >> from >> to;
        REP(j, from - 1, to - 1){
            adj[i].push_back(j);
        }
    }
}

bool dfs(int here){
    if(visited[here]) return false;
    visited[here] = true;

    rep(i, 0, adj[here].size()){
        int there = adj[here][i];
        if(book[there] == -1 || dfs(book[there])){
            book[there] = here;
            return true;
        }
    }
    return false; 
}

int bipartiteMatch(){
    int ret = 0;

    rep(i, 0, m){
        visited = vector<bool>(m, false);
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