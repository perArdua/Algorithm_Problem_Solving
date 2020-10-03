#ifndef __BOJ_10552_DOM_H__
#define __BOJ_10552_DOM_H__

#include <iostream>
#include <cstring>
#define endl "\n"

using namespace std;

int n, m, p;
int preference[100001];

bool ok[100001];
int changes = 0;

void dfs(int curChannel){
    if(!ok[curChannel]){
        ok[curChannel] = true;
        if(preference[curChannel] != 0){
            ++changes;
            dfs(preference[curChannel]);
        }
    }else{
        changes = -1;
        return;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> p;

    for(int i = 1; i <= n; ++i){
        int favor, hate;
        cin >> favor >> hate;
        if(preference[hate] == 0){
            preference[hate] = favor; 
        }
    }

    dfs(p);
    cout << changes << endl;
    return 0;
}
#endif // __BOJ_10552_DOM_H__