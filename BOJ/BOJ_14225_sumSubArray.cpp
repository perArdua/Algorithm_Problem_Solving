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

vector<int> v;

void pre_calc(int idx, int cur_sum, const vector<int>& arr){
    if(idx == arr.size()){
        if(!cur_sum) return;
        v.pb(cur_sum);
        return;
    }
    pre_calc(idx + 1, cur_sum, arr);
    pre_calc(idx + 1, cur_sum + arr[idx], arr);
}

int main(){
    FAST;
    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> vec(n);
    for(auto& e: vec) cin >> e;
    
    sort(all(vec));

    pre_calc(0, 0, vec);
    
    sort(all(v));

    for(auto i = 1; i <= v.back() + 1; ++i){
        if(!binary_search(all(v), i)){
            cout << i;
            break;
        }
    }
    return 0;
}
