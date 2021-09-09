#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define pb push_back
#define INF 987654321

using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    rep(i, 0, n) cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll res = numeric_limits<ll>::max();
    rep(i, 1, n){
        ll tmp = (arr[0] * i) + (arr[i] * (n - i));
        res = min(res, (k - 1 + tmp) / tmp);
    }
    cout << res;
    return 0;
}
