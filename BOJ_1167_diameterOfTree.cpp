#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#define endl "\n"

struct Node{
    int linked;
    int cost;
    Node(int _linked, int _cost) : linked{_linked}, cost{_cost} {}
};

using namespace std;
vector<Node> node[100001];
int n;
bool vistied[100001];
pair<int, int> bfs(int start){
    memset(vistied, false, sizeof(vistied));
    
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    vistied[start] = true;
    int ret = start, maxCost = 0;
    while(!q.empty()){
        int startNode = q.front().first;
        int curCost = q.front().second; q.pop();
        if(maxCost < curCost){
            ret = startNode;
            maxCost = curCost;
        }
        for(int i = 0; i < node[startNode].size(); ++i){
            int nextLink = node[startNode][i].linked;
            if(vistied[nextLink]) continue;
            vistied[nextLink] = true;
            int additionalCost = node[startNode][i].cost;
            q.push(make_pair(nextLink, curCost + additionalCost));
        }
    }
    return make_pair(ret, maxCost);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i){
        int vertex;
        cin >> vertex;
        while(true){
            int a, b;
            cin >> a;
            if(a == -1) break;
            cin >> b;
            node[vertex].push_back(Node(a, b));
        }
    }
    cout << bfs(bfs(1).first).second << endl;
    return 0;
}