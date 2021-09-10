#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define pii pair<int, int>
#define pb push_back
#define INF 987654321
#define MAX 1010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int d[MAX][MAX];
int a[MAX][MAX];
int n, m, res = 0;
string tmp;

int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    rep(i, 0, n){
        cin >> tmp;
        rep(j, 0, m){
            a[i][j] = tmp[j] - '0';
            if(a[i][j]) d[i][j] = 1;
        }
    }
    rep(i, 0, n){
        rep(j, 0, m){
            if(i && j){
                if(a[i][j] && a[i - 1][j - 1] && a[i - 1][j] && a[i][j - 1]){
                    d[i][j] = min({d[i - 1][j - 1], d[i - 1][j], d[i][j - 1]}) + 1;
                }
            }
        }
    }
    rep(i, 0, n) rep(j, 0, m) res = max(res, d[i][j]);
    cout << res * res;
    return 0;
}
