#include <iostream>
#include <string>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;
const int INF = 987654321;

int n, k, cnt = 0;
string ans;
int dfs(int cur){
    if(cur > n) return -1;
    if(cur == n){
        ++cnt;
        if(cnt == k) return INF;
        return -1;
    }
    int res = -1;
    REP(i, 1, 3){
        ans.push_back(static_cast<char> (i + '0'));
        ans.push_back('+');
        res = dfs(cur + i);
        if(res == INF) return INF;
        ans.pop_back();
        ans.pop_back();
    }
    return res;
}

int main(){
    FAST;
    cin >> n >> k;
    if(dfs(0) == INF){
        ans.pop_back();
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}
// ?