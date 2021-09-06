#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define pii pair<int, int>
#define pb push_back
#define INF 987654321

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MAX_NUMBER = 300010;

int main(){
    FAST;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int xors[MAX_NUMBER] = {0,};
    // pre calc
    rep(i, 1, MAX_NUMBER){
        xors[i] = xors[i - 1] ^ i;
    }
    int t, a, b;
    cin >> t;
    rep(tc, 0, t){
        // len(MEX) + 0 or 1 or 2
        cin >> a >> b;
        if(xors[a - 1] == b) cout << a << endl;
        else{
            if((xors[a - 1] ^ b) == a) cout << a + 2 << endl;
            else cout << a + 1 << endl;
        }
    }
#ifndef ONLINE_JUDGE
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}