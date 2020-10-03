#include <iostream>
#include <cstring>
#define endl "\n"

using namespace std;
int n;
int connection[100000];
int ok[100000];
enum status {notVisited, cycle, visited, notCycle = -2};
int dfs(int curNode){
    if(ok[curNode] == visited) return curNode;
    if(ok[curNode] == cycle || ok[curNode] == notCycle) return notCycle;
    ok[curNode] = visited;

    int nextNode = connection[curNode];
    int res = dfs(nextNode);
    if(res >= 0){
        ok[curNode] = cycle;
        if(res == curNode) return notCycle;
        else return res;
    }
    else ok[curNode] = notCycle;
    return notCycle;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;

        int res = 0;
        
        for(int i = 0; i < n; ++i){
            int tmp;
            cin >> tmp;
            --tmp;
            connection[i] = tmp;
        }

        for(int i = 0; i < n; ++i){
            if(ok[i] == notVisited){
                dfs(i);
            }
        }
            
        for(int i = 0; i < n; ++i){
            if(ok[i] != cycle){
                ++res;
            }
        }

        cout << res << endl;
        memset(ok, 0, sizeof(ok));
        memset(connection, 0, sizeof(connection));
    }

    return 0;
}