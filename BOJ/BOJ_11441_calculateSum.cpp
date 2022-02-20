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
    int n, tmp;
    cin >> n;
    REP(i, 1, n){
        cin >> tmp;
        arr[i] = arr[i - 1] + tmp;
    }
    int a, b;
    cin >> tmp;
    rep(i, 0, tmp){
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << endl;
    }
    return 0;
}
