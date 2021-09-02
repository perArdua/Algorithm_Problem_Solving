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


int main(){
    FAST;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t, n;
    string src, dest;
    cin >> t;
    rep(tc, 0, t){
        int res = 0;
        cin >> n >> dest >> src;
        rep(i, 0, n){
            if(src[i] == '1'){
                if(i - 1 >= 0 && dest[i - 1] == '1'){
                    dest[i - 1] = '2';
                    ++res;
                    continue;
                }else if(dest[i] == '0'){
                    dest[i] = '2';
                    ++res;
                    continue;
                }else if(i + 1 < n && dest[i + 1] == '1'){
                    dest[i + 1] = '2';
                    ++res;
                    continue;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}