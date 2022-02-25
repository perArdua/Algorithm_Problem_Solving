#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(auto i = a; i < b; ++i)
#define REP(i, a, b) for(auto i = a; i <= b; ++i)
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define INF 987654321

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int arr[201][201];
int prefix_sum[201][201];
int n, m;

int grid_sum(int y1, int x1, int y2, int x2){
    int ret = prefix_sum[y2][x2];
    if(y1 > 0) ret -= prefix_sum[y1 - 1][x2];
    if(x1 > 0) ret -= prefix_sum[y2][x1 - 1];
    if(y1 > 0 && x1 > 0) ret += prefix_sum[y1 - 1][x1 - 1];
    return ret;
}

int main(){
    FAST;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    REP(i, 1, n) REP(j, 1, m) cin >> arr[i][j];

    REP(i, 1, n){
        REP(j, 1, m){
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + arr[i][j];
        }
    }

    int res = -INF;

    REP(i, 1, n){
        REP(j, 1, m){
            REP(k, i, n){
                REP(l, j, m){
                    res = max(res, grid_sum(i, j, k, l));
                }
            }
        }
    }

    cout << res;

    return 0;
}
