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

int main(){
    FAST;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t, n;
    cin >> t;
    rep(tc, 0, t){
        cin >> n;
        vector<char> domino(n);
        for(auto& e : domino) cin >> e;
        for(auto& e : domino){
            if(e == 'U') cout << 'D';
            else if(e == 'D') cout << 'U';
            else cout << e;
        }
        cout << endl;
    }
#ifndef ONLINE_JUDGE
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}