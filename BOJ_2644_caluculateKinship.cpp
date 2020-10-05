#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define endl "\n"

using namespace std;

int n;
vector<int> relationship[101];

int dist[101];
int o1, o2;

void bfs(){
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(o1);
    dist[o1] = 0;
    int res = -1;
    bool flag = true;
    while(flag && !q.empty()){
        int curNode = q.front(); q.pop();
        for(auto nextNode : relationship[curNode]){
            if(dist[nextNode] != -1) continue;
            dist[nextNode] = dist[curNode] + 1;
            if(nextNode == o2){
                flag = false;
                break;
            }
            q.push(nextNode);
        }
    }
    res = dist[o2] == -1 ? -1 : dist[o2];
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> o1 >> o2;
    int tmp;
    cin >> tmp;
    for(int i = 0; i < tmp; ++i){
        int x, y;
        cin >> x >> y;
        relationship[x].push_back(y);
        relationship[y].push_back(x);
    }
    bfs();
    return 0;
}
// ?