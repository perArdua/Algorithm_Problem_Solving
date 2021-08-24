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

int n, m;
double cache[1001][2002];

void memory_fill(){
    for(auto& arr : cache) for(auto& e : arr) e = -1.0;
}

double climb(int days = 0, int climbed = 0){
    if(days == m) return climbed >= n;
    double& ret = cache[days][climbed];
    if(ret != -1) return ret;
    return ret = 0.75 * climb(days + 1, climbed + 2) + 0.25 * climb(days + 1, climbed + 1);
}

int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    cout.precision(10);
    cout << fixed;
    rep(tc, 0, t){
        memory_fill();
        cin >> n >> m;
        cout << climb() << endl;
    }
    return 0;
}
