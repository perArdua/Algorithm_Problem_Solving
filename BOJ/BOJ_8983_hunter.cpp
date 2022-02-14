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
    int m, n;
    ll l, x, y;
    cin >> m >> n >> l;
    vector<ll> shooting_site(m);
    for(auto& e: shooting_site) cin >> e;
    vector<ll> pre_calc;
    sort(shooting_site.begin(), shooting_site.end());
    while(n--){
        cin >> x >> y;
        auto it = lower_bound(shooting_site.begin(), shooting_site.end(), x);
        if(it == shooting_site.end()){
            pre_calc.pb(abs(shooting_site.back() - x) + y);
        }else if(*it == x){
            pre_calc.pb(y);
        }else if(*it != x){
            if(it == shooting_site.begin()) pre_calc.pb(abs(*it - x) + y);
            else pre_calc.pb(min(abs(*it - x), abs(*(it - 1) - x)) + y);
        }
    }
    sort(pre_calc.begin(), pre_calc.end());
    cout << pre_calc.size() - (pre_calc.end() - upper_bound(pre_calc.begin(), pre_calc.end(), l));
    return 0;
}
