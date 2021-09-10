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
    cout << fixed;
    cout.precision(12);
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<double> p(n);
    for(auto& e : p) cin >> e;
    rep(i, 0, n - 1){
        p[i] += p[i] * (1 - p[i + 1]) + p[i + 1] * (1 - p[i]);
    }
    double res = accumulate(p.begin(), p.end(), (double)0);
    cout << res;
    return 0;
}