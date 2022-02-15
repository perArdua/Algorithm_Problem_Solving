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
    ll t;
    cin >> t;
    int n, m;
    
    cin >> n;
    vector<int> vec_a(n);
    for(auto& e: vec_a) cin >> e;

    cin >> m;
    vector<int> vec_b(m);
    for(auto& e: vec_b) cin >> e;

    vector<int> v, w;

    for(auto i = 0; i < vec_a.size(); ++i){
        int sum = 0;
        for(auto j = i; j < vec_a.size(); ++j){
            sum += vec_a[j];
            v.pb(sum);
        }
    }
    
    for(auto i = 0; i < vec_b.size(); ++i){
        int sum = 0;
        for(auto j = i; j < vec_b.size(); ++j){
            sum += vec_b[j];
            w.pb(sum);
        }
    }

    sort(w.begin(), w.end());

    ll res = 0;

    for(const auto& e: v){
        ll diff = t - e;
        res += upper_bound(w.begin(), w.end(), diff) - lower_bound(w.begin(), w.end(), diff);
    }

    cout << res;
    return 0;
}
