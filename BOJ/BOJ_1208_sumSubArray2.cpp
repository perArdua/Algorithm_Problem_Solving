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

map<int, int> mp;
ll res;
int n, s;

void bf_left(int idx, int cur_sum, const vector<int>& v){
    if(idx == n / 2){
        ++mp[cur_sum];
        return;
    }
    bf_left(idx + 1, cur_sum, v);
    bf_left(idx + 1, cur_sum + v[idx], v);
}

void bf_right(int idx, int cur_sum, const vector<int>& v){
    if(idx == v.size()){
        res += mp[s - cur_sum];
        return;
    }
    bf_right(idx + 1, cur_sum, v);
    bf_right(idx + 1, cur_sum + v[idx], v);
}

int main(){
    FAST;
    // freopen("input.txt", "r", stdin);

    cin >> n >> s;

    vector<int> vec(n);
    for(auto& e: vec) cin >> e;

    bf_left(0, 0, vec);
    bf_right(n / 2, 0, vec);

    if(!s) cout << res - 1;
    else cout << res;

    return 0;
}
