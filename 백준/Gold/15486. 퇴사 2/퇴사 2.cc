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

int cache[1500001];
int n;
vector<pii> vec;

int f(int days) {
    if (days > n) return -INF;
    if (days == n) return 0;
    
    int& ret = cache[days];
    if (ret != -1) return ret;

    ret = 0;
    ret = max(f(days + 1), f(days + vec[days].first) + vec[days].second);
    return ret;
}

int main(){
    FAST;
#ifndef ONLINE_JUDGE
    clock_t start = clock();
    freopen("input.txt", "r", stdin);
#endif

    
    memset(cache, -1, sizeof(cache));
    cin >> n;
    vec = vector<pii>(n);
    for(auto& e : vec) cin >> e.first >> e.second;
    // cout << "here" << endl;
    cout << f(0);
#ifndef ONLINE_JUDGE
    cout << endl << "elapsed time: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}
