#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>
#define pb push_back
#define INF 987654321

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1000000007;

int cache[101];

int solve(int n){
    if(n <= 2) return n;
    int& ret = cache[n];
    if(ret != -1) return ret;
    return ret = (solve(n - 1) + solve(n - 2)) % MOD;
}

int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    rep(tc, 0, t){
        int n;
        cin >> n;
        memset(cache, -1, sizeof(cache));
        cout << solve(n) << endl;
    }
    return 0;
}
