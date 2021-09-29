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

int main(){
    FAST;
//     freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto& e : v) cin >> e;
    sort(all(v));
    cout << v[k - 1];
    return 0;
}
