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

int solve(vector<int>& a, vector<int>& b){
    int ret = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(const auto& e: b){
        ret += a.end() - upper_bound(a.begin(), a.end(), e);
    }
    return ret;
}

int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<int> vec_a(n);
        vector<int> vec_b(m);
        for(auto& e: vec_a) cin >> e;
        for(auto& e: vec_b) cin >> e;
        cout << solve(vec_a, vec_b) << endl;
    }
    return 0;
}
