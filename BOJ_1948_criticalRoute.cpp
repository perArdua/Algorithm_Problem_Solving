#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define INF 987654321
using namespace std;

struct Info{
    int next;
    int cost;

    Info(int next, int cost) : next(next), cost(cost) {}
};

int n, m, src, dest, max_dis;
bool check[10000 + 1];
int max_time[10000 + 1];
int indegree[10000 + 1];
vector<Info> adj[10000 + 1];
vector<Info> reverse_adj[10000 + 1];

inline int max(int a, int b){
    if(a >= b) return a;
    return b;
}


void topological_sort(){
    queue<Info> q;
    q.push(Info(src, 0));

    while(!q.empty()){
        auto cur_info = q.front(); q.pop();
        auto cur_node = cur_info.next;
        auto cur_time = cur_info.cost;

        for(auto& next_node: adj[cur_node]){
            max_time[next_node.next] = max(max_time[next_node.next], next_node.cost + cur_time);
            if(--indegree[next_node.next] == 0){
                q.push(Info(next_node.next, max_time[next_node.next]));
            }
        }
    }
}

void tracking_route(){
    queue<int> q;
    q.push(dest);
    while(!q.empty()){
        auto cur_node = q.front(); q.pop();

        for(auto& next_node: reverse_adj[cur_node]){
            if(max_time[cur_node] == max_time[next_node.next] + next_node.cost){
                ++max_dis;
                if(!check[next_node.next]){
                    check[next_node.next] = true;
                    q.push(next_node.next);
                }
            }
        }
    }

}

void solve(){
    topological_sort();
    tracking_route();
}

void input(){
    cin >> n >> m;
    rep(i, 0, m){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(Info(v, c));
        reverse_adj[v].push_back(Info(u, c));
        ++indegree[v];
    }
    cin >> src >> dest;
}

int main(){
    FAST;
    input();
    solve();
    cout << max_time[dest] << endl;
    cout << max_dis << endl;
    return 0;
}