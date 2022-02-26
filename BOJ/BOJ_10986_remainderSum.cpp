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

int n, m;
int cnt[1'001];

int main(){
    FAST;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m;
    ll tmp, cur = 0, next = 0;
    REP(i, 1, n){
        cin >> tmp;
        next = (cur + tmp) % m;
        ++cnt[next];
        cur = next;
    }

    ++cnt[0];

    ll res = 0;

    rep(i, 0, m){
        if(cnt[i] < 2) continue;
        res += cnt[i] * (cnt[i] - 1) / 2;
    }
    
    cout << res;

    return 0;
}
