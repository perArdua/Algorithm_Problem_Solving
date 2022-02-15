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
    int n;
    cin >> n;
    vector<int> vec(n);
    for(auto& e: vec) cin >> e;
    sort(all(vec));
    int res = 0;

    for(auto i = 0; i < n; ++i){
        int l = 0, r = n - 1;
        
        while(l < r){
            if(i == l){
                ++l;
                continue;
            }
            if(i == r){
                --r;
                continue;
            }

            int tmp = vec[l] + vec[r];
            if(tmp == vec[i]){
                ++res;
                break;
            }else if(tmp > vec[i]) --r;
            else ++l;
        }
    }

    cout << res;
    return 0;
}
