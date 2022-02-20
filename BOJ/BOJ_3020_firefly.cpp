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
    // freopen("input.txt", "r", stdin);
    int n, h;
    cin >> n >> h;

    vector<int> upper(n / 2);
    vector<int> lower(n / 2);

    for(auto i = 0; i < n / 2; ++i){
        cin >> lower[i] >> upper[i];
    }

    sort(all(lower));
    sort(all(upper));

    int res = INF, num = 0;

    for(auto cur_height = 1; cur_height <= h; ++cur_height){
        int cnt = 0;
        cnt += (n / 2) - (lower_bound(all(lower), cur_height) - lower.begin()); 
        cnt += (n / 2) - (upper_bound(all(upper), h - cur_height) - upper.begin());
        if(res > cnt){
            res = cnt;
            num = 1;
        }else if(res == cnt) ++num;
    }

    cout << res << ' ' << num;
    return 0;
}
