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
typedef unsigned long long ull;

int cache[501];
int n;

int lis(const vector<int>& s, int here){
    int& ret = cache[here + 1];
    if(ret != -1) return ret;
    ret = 1;
    for(int there = here + 1; there < n; ++there){
        if(here == -1 || s[here] < s[there]){
            ret = max(lis(s, there) + 1, ret);
        } 
    }
    return ret;
}

int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    rep(tc, 0, t){
        memset(cache, -1, sizeof(cache));
        cin >> n;
        vector<int> sq(n);
        for(auto& e : sq) cin >> e;
        cout << lis(sq, -1) - 1 << endl;
    }
    return 0;
}
