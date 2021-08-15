#include <iostream>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

int dp[10001];

int main(){
    FAST;
    dp[0] = 1;
    REP(i, 1, 3){
        REP(j, 1, 10000){
            if(j - i >= 0) dp[j] += dp[j - i];
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