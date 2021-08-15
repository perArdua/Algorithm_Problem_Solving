#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"

using namespace std;

vector<int> edge[101];
bool check[101];
int bfs(){
    int ret = 0;
    int startNode = 1;
    queue<int> q;
    q.push(startNode);
    check[startNode] = true;
    while(!q.empty()){
        int curNode = q.front(); q.pop();
        for(int nextNode : edge[curNode]){
            if(check[nextNode]) continue;
            q.push(nextNode);
            check[nextNode] = true;
            ret += 1;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, p;
    cin >> n >> p;
    for(int i = 0; i < p; ++i){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int res = 0;
    cout << bfs() << endl;
    return 0;
}