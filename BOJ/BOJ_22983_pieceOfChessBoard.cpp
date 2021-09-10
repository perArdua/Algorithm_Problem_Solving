#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define pii pair<int, int>
#define pb push_back
#define INF 987654321
#define MAX 3010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll r, c, res = 0;
int dp[MAX][MAX];
char board[MAX][MAX];
string tmp;

int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    cin >> r >> c;
    rep(i, 0, r){
        cin >> tmp;
        rep(j, 0, c){
            board[i][j] = tmp[j];
            dp[i][j] = 1;
        }
    }
    rep(i, 0, r){
        rep(j, 0, c){
            if(i && j){
                if(board[i][j] == board[i - 1][j - 1] && board[i][j] != board[i - 1][j] && board[i][j] != board[i][j - 1]){
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }
    }
    rep(i, 0, r) rep(j, 0, c) res += dp[i][j];
    cout << res << endl;
    return 0;
}
