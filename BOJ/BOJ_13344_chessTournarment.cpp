#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

int n, m, num_child = 0;
int parent[50000];
int set_rank[50000];
int indegree[50000];
vector<vector<int> > adj(50000, vector<int>());
vector<pair<int, int>> edges;

int find(int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return;
    if(set_rank[u] < set_rank[v]) swap(u, v);
    parent[v] = u;
    if(set_rank[u] == set_rank[v]) ++set_rank[u];
}

void initBase(){
    rep(i, 0, n){
        parent[i] = i;
        set_rank[i] = 1;
    }
}

void input(){
    cin >> n >> m;
    initBase();
    rep(i, 0, m){
        int left, right;
        char op;
        cin >> left >> op >> right;
        if(op == '='){
            merge(left, right);
        }else{
            edges.push_back(make_pair(left, right));
        }
    }
}

void makeGraph(){
    for(auto i = 0; i < edges.size(); ++i){
        auto left = find(edges[i].first);
        auto right = find(edges[i].second);
        if(left == right){
            cout << "inconsistent";
            exit(0);
        }
        if(find(adj[right].begin(), adj[right].end(), left) != adj[right].end()){
            cout << "inconsistent";
            exit(0);
        }
        else if(find(adj[left].begin(), adj[left].end(), right) == adj[left].end()){
            adj[left].push_back(right);
            ++indegree[right];
        }
    }
}

void updateIndegree(){
    for(auto i = 0; i < n; ++i){
        if(parent[i] != i){
            indegree[i] = -1;
            ++num_child;
        }
    }
}

void initGraph(){
    makeGraph();
    updateIndegree();
}

bool topologicalSort(){
    queue<int> q;
    int visited_node = 0;
    for(auto here = 0; here < n; ++here){
        if(indegree[here]) continue;
        q.push(here);
        ++visited_node;
    }

    if(q.empty()) return false;

    while(!q.empty()){
        auto cur_node = q.front(); q.pop();
        for(auto next_node : adj[cur_node]){
            if(--indegree[next_node] == 0){
                q.push(next_node);
                ++visited_node;
            }
        }
    }
    return visited_node == (n - num_child) ? true : false;
}

int main(){
    FAST;
    input();
    initGraph();
    if(topologicalSort()){
        cout << "consistent";
    }else{
        cout << "inconsistent";
    }
    return 0;
}