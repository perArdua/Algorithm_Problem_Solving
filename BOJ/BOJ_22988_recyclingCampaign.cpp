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
typedef long double ld;
int main(){
    FAST;
    freopen("input.txt", "r", stdin);
    int res = 0;
    ld n, x;
    cin >> n >> x;
    vector<ld> vec(n);
    for(auto& e : vec) cin >> e;
    int lo = 0, hi = n - 1;
    sort(all(vec));
    
    while(hi >= 0 && vec[hi] >= x){
        ++res;
        --n;
        --hi;
    }
    while(lo < hi){
        ll cal = vec[lo] + vec[hi];
        if(x / 2 <= cal){
            ++res;
            ++lo;
            --hi;
            n -= 2;
        }else ++lo;
    }
    cout << res + n / 3;
    return 0;
}