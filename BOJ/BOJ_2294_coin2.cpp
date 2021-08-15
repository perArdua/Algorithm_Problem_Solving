#include <iostream>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

int kind[101];
int dp[100001];

inline int min(int a, int b){
    if(a <= b) return a;
    return b;
}

int main(){
    FAST;
    int n, k;
    cin >> n >> k;
    REP(i, 1, n) cin >> kind[i];
    fill(dp + 1, dp + 100001, 100001);
    REP(i, 1, n){
        REP(j, kind[i], k){
            dp[j] = min(dp[j], dp[j - kind[i]] + 1);
        }
    }
    if(dp[k] == 100001) cout << -1;
    else cout << dp[k];
    return 0;
}
// ?