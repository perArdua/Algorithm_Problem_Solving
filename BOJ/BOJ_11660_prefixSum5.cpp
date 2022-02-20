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

int arr[1025][1025];
int prefix_sum[1025][1025];

int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    int n, m, tmp;
    
    cin >> n >> m;

    REP(i, 1, n){
        REP(j, 1, n){
            cin >> arr[i][j];
        }
    }

    REP(i, 1, n){
        REP(j, 1, n){
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + arr[i][j];
        }
    }

    int x1, y1, x2, y2;
    rep(i, 0, m){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix_sum[x2][y2] - prefix_sum[x1 - 1][y2] - prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1] << endl;
    }

    return 0;
}
