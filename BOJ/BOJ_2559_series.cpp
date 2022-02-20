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

int arr[100'001];


int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    int n, k, tmp;
    cin >> n >> k;
    REP(i, 1, n){
        cin >> tmp;
        arr[i] = arr[i - 1] + tmp;
    }

    vector<int> dp(n - k + 1);

    rep(i, 0, n - k + 1){
        dp[i] = arr[i + k] - arr[i];
    }
    cout << *max_element(all(dp));
    return 0;
}
