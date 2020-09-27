#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"

using namespace std;
int parent[100001];
int n;
vector<int> link[100001];
bool visited[100001];
void solve(){
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int startNode = q.front(); q.pop();
        for(auto e : link[startNode]){
            if(visited[e]) continue;
            visited[e] = true;
            parent[e] = startNode;
            q.push(e);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n-1; ++i){
        int u, v;
        cin >> u >> v;
        link[u].push_back(v);
        link[v].push_back(u);
    }
    solve();
    for(int i = 2; i <= n; i++){
        cout << parent[i] << endl;
    }

    return 0;
}