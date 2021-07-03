#include <bits/stdc++.h>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>
#define pb push_back
#define INF 987654321

using namespace std;

int n, m, memory[101], cost[101], cache[101][10001];


int dfs(int idx, int co){
    if(idx >= n) return 0;
    int& ret = cache[idx][co];
    if(ret != -1) return ret;
    
    ret = dfs(idx + 1, co);
    if(cost[idx] <= co) ret = max(ret, memory[idx] + dfs(idx + 1, co - cost[idx]));

    return ret;
}

int main(){
    FAST;
    cin >> n >> m;
    rep(i, 0, n){
        cin >> memory[i];
    }
    rep(i, 0, n){
        cin >> cost[i];
    }
    memset(cache, -1, sizeof(cache));

    int res = 0;
    int lo = 0, hi = accumulate(cost, cost + n, 0);
    
    while(lo < hi){
        int mid = (lo + hi) >> 1;
        if(dfs(0, mid) >= m){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }

    cout << lo;
    
    return 0;
} 