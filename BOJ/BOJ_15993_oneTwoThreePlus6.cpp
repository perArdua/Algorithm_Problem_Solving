#include <iostream>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

const int MOD = 1e9 + 9;
int dp[2][1000001];

int main(){
    FAST;
    dp[1][1] = 1;
    dp[0][2] = 1;
    dp[1][2] = 1;
    dp[0][3] = 2;
    dp[1][3] = 2;
    REP(i, 4, 1000000){
        dp[0][i] += dp[1][i - 1];
        dp[0][i] %= MOD; 
        dp[0][i] += dp[1][i - 2];
        dp[0][i] %= MOD;
        dp[0][i] += dp[1][i - 3];
        dp[0][i] %= MOD;

        dp[1][i] += dp[0][i - 1];
        dp[1][i] %= MOD; 
        dp[1][i] += dp[0][i - 2];
        dp[1][i] %= MOD;
        dp[1][i] += dp[0][i - 3];
        dp[1][i] %= MOD;

    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[1][n] << ' ' << dp[0][n] << endl;
    }
    return 0;
}
// ?

// cache = [[0] * 100001 for _ in range(2)]
// cache[1][1] = 1;
// cache[0][2] = 1;
// cache[1][2] = 1;
// cache[0][3] = 2;
// cache[1][3] = 2;


// MOD = int(1e9 + 9)

// for i in range(4, 10**5 + 1) :
//     cache[0][i] += cache[1][i - 1]
//     cache[0][i] %= MOD
//     cache[0][i] += cache[1][i - 2]
//     cache[0][i] %= MOD
//     cache[0][i] += cache[1][i - 3]
//     cache[0][i] %= MOD
//     cache[1][i] += cache[0][i - 1]
//     cache[1][i] %= MOD
//     cache[1][i] += cache[0][i - 2]
//     cache[1][i] %= MOD
//     cache[1][i] += cache[0][i - 3]
//     cache[1][i] %= MOD

// for _ in range(int(input())) :
//     n = int(input())
//     print(cache[1][n], cache[0][n])    
