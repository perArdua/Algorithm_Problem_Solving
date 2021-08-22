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

int cache[101][101];

bool solve(const string& W, const string& S, int w = 0, int s = 0){
    int& ret = cache[w][s];
    if(ret != -1) return ret;

    while(w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s])){
        return ret = solve(W, S, w + 1, s + 1);
    }

    if(w == W.size()) return ret = (s == S.size());

    if(W[w] == '*'){
        if(solve(W, S, w + 1, s) || (s < S.size() && solve(W, S, w, s + 1))) return ret = 1;
    }
    return ret = 0;
}

int main(){
    FAST;
#ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    rep(tc, 0, t){
        int n;
        string src;
        vector<string> res;
        cin >> src >> n;
        rep(i, 0, n){
            memset(cache, -1, sizeof(cache));
            string tmp;
            cin >> tmp;
            if(solve(src, tmp) == 1) res.pb(tmp);
        }
        sort(res.begin(), res.end());
        for(auto& s : res) cout << s << endl;
    }
    return 0;
}
