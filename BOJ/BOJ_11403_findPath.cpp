#include <iostream>
#include <vector>
#include <cstring>
#define endl "\n"

using namespace std;

vector<int> a[100];
bool visited[100];

void dfs(int node){
    for(auto nextNode : a[node]){
        if(visited[nextNode]) continue;
        visited[nextNode] = true;
        dfs(nextNode);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int tmp;
            cin >> tmp;
            if(!tmp) continue;
            a[i].push_back(j);
        }
    }

    for(int i = 0; i < n; ++i){
        dfs(i);
        for(int j = 0; j < n; ++j) cout << visited[j] << " ";
        cout << endl;
        memset(visited, false, sizeof(visited));
    }
    return 0;
}