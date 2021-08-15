#include <iostream>
#include <vector>
#include <utility>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(auto i = a; i < b; ++i)
#define REP(i, a, b) for(auto i = a; i <= b; ++i)

using namespace std;

typedef pair<int, int> pii;

int n, m;
int cache[10001];
vector<pii> info;

inline int max(int a, int b){
    if(a > b) return a;
    return b;
}

inline int min(int a, int b){
    if(a < b) return a;
    return b;
}

int main(){
    FAST;
    cin >> n >> m;
    rep(i, 0, n){
        int v, c, k;
        cin >> v >> c >> k;
        for(int i = 1; k > 0 ; i <<= 1){
            int tmp = min(i, k);
            info.push_back({v * tmp, c * tmp});
            k -= tmp;
        }
    }

    rep(i, 0, info.size()){
        for(auto j = m; j >= 0; --j){
            if(info[i].first <= j){
                cache[j] = max(cache[j], cache[j - info[i].first] + info[i].second);
            }
        }
    }
    cout << cache[m];
    
    return 0;
}
// ?