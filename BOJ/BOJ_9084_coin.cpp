#include <iostream>
#include <cstring>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

int kind[21];
int dp[10001];

int main(){
    FAST;
    int t, n, tar;
    cin >> t;
    while(t--){
        memset(kind, 0, sizeof(kind));
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        cin >> n;
        REP(i, 1, n) cin >> kind[i];
        cin >> tar;
        REP(i, 1, n){
            for(int j = kind[i]; j <= tar; ++j){
                dp[j] += dp[j - kind[i]];
            }
        }
        cout << dp[tar] << endl;
    }
    return 0;
}
// ?