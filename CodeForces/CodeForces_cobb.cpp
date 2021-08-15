#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>
#define pb push_back
#define INF 987654321

using namespace std;
typedef long long ll;

int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    rep(tc, 0, t){
        int n, k;
        cin >> n >> k;
        vector<ll> arr(n);
        for(auto& x : arr) cin >> x;
        ll res = n * (n - 1) - k * (arr[n - 1] | arr[n - 2]);
        rep(i, 0, n){
            rep(j, i + 1, n){
                if(1LL * (i + 1) * (j + 1) <= res) break;
                res = max(res, 1LL * (i + 1) * (j + 1) - 1LL * k * (arr[i] | arr[j]));
            }
        }
        cout << res << endl;
    }
    return 0;
}
