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


int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        ll a, b, res;
        cin >> a >> b;
        if(a >= b) res = ((b + 1) * ((a - b) + a) << 1);
        else res = ((a * (1 + a)) << 1);
        cout << res << endl;
    }
    return 0;
}
