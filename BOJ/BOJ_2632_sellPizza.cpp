#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define INF 987654321

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    int t, m, n;
    cin >> t >> m >> n;

    vector<int> vec_a(m);
    vector<int> vec_b(n);

    for(auto& e: vec_a) cin >> e;
    for(auto& e: vec_b) cin >> e;

    vector<int> v, w;

    for(auto i = 0; i < m; ++i){
        int cur_forward_idx = i;
        int forward_sum = 0;

        for(auto j = 0; j < m - 1; ++j){
            forward_sum += vec_a[cur_forward_idx];
            v.pb(forward_sum);
            cur_forward_idx += 1;
            if(cur_forward_idx == m) cur_forward_idx = 0;
        }
    }

    for(auto i = 0; i < n; ++i){
        int cur_forward_idx = i;
        int forward_sum = 0;

        for(auto j = 0; j < n - 1; ++j){
            forward_sum += vec_b[cur_forward_idx];
            w.pb(forward_sum);
            cur_forward_idx += 1;
            if(cur_forward_idx == n) cur_forward_idx = 0;
        }
    }

    v.pb(0);
    v.pb(accumulate(all(vec_a), 0));
    w.pb(0);
    w.pb(accumulate(all(vec_b), 0));
    sort(all(w));

    int res = 0;

    for(const auto& e: v){
        if(e > t) continue;
        auto [lo, hi] = equal_range(all(w), t - e);
        res += hi - lo;
    }

    cout << res;
    return 0;
}
