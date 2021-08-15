#include <iostream>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

typedef unsigned long long ull;

const ull MOD = static_cast<ull>(1e9 + 9);

ull dp[100001];

int main(){
    FAST;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    REP(i, 4, 100000){
        if(i >= 2){
            dp[i] += dp[i - 2];
            dp[i] %= MOD;
        }
        if(i >= 4){
            dp[i] += dp[i - 4];
            dp[i] %= MOD;
        }
        if(i >= 6){
            dp[i] += dp[i - 6];
            dp[i] %= MOD;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}
// ?
