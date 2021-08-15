#include <iostream>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

const int MOD = 1e9 + 9; 

int t, n, m;
int dp[1001][1001];

int main(){
    FAST;
    dp[1][1] = 1, dp[2][1] = 1, dp[2][2] = 1, dp[3][1] = 1, dp[3][2] = 2, dp [3][3] = 1;
    REP(i, 4, 1000){
        REP(j, 1, 1000){
            dp[i][j] += dp[i - 1][j - 1];
            dp[i][j] %= MOD;
            dp[i][j] += dp[i - 2][j - 1];
            dp[i][j] %= MOD;
            dp[i][j] += dp[i - 3][j - 1];
            dp[i][j] %= MOD;
        }
    }
    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << dp[n][m] << endl;
    }
    return 0;
}
// ?

// cache = [[0] * 1001 for _ in range(1001)]
// cache[1][1] = 1
// cache[2][1] = 1
// cache[2][2] = 1
// cache[3][1] = 1
// cache[3][2] = 2
// cache[3][3] = 1

// MOD = int(1e9 + 9)

// for i in range(4, 1001) :
//     for j in range(1, 1001) :
//         cache[i][j] = cache[i - 1][j - 1] + cache[i - 2][j - 1] + cache[i - 3][j - 1]
//         cache[i][j] %= MOD


// for _ in range(int(input())) :
//     n, m = map(int, input().split(' '))
//     print(cache[n][m])    
