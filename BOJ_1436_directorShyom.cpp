#include <iostream>
#include <string>
#define endl "\n"

using namespace std;

int dfs(int n, int cnt, int x){
    if(n == cnt) return x - 1;

    string tmp = to_string(x);
    if(tmp.find("666") != string::npos){
        cnt += 1;
    }

    return dfs(n, cnt, x + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << dfs(n, 0, 666);
    return 0;
}