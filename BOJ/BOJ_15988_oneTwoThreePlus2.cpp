#include <iostream>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

typedef unsigned long long ull;
const ull MOD = 1e9 + 9;
ull dp[1000001];

int main(){
    FAST;
    int t;
    cin >> t;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    REP(n, 4, 1e6){
        dp[n] = (dp[n - 1] + dp[n - 2] + dp[n - 3]) % MOD;
    }
    while(t--){
        ull n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}
// ?