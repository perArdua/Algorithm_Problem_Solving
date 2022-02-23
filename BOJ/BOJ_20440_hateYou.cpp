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

int main(){
    FAST;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    unordered_map<int, int> mp;

    int a, b;

    rep(i, 0, n){
        cin >> a >> b;
        
        if(mp[a]) ++mp[a];
        else mp[a] = 1;

        if(mp[b]) --mp[b];
        else mp[b] = -1;
    }

    vector<pii> vec {all(mp)};
    sort(all(vec));
    
    int res = -1, cur = 0;
    int lo = 0, hi = -1;

    rep(i, 0, vec.size()){
        cur += vec[i].second;
        if(cur > res){
            res = cur;
            lo = vec[i].first, hi = -1;
        }else if(cur < res){
            if(hi == -1) hi = vec[i].first;
        }
    }
    
    cout << res << endl;
    cout << lo << ' ' << hi;

    return 0;
}
