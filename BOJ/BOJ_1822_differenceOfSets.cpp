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
    int a, b;
    cin >> a >> b;
    vector<int> vec_a(a);
    vector<int> vec_b(b);
    vector<int> res;
    int sum = 0;
    for(auto& e: vec_a) cin >> e;
    for(auto& e: vec_b) cin >> e;
    sort(vec_a.begin(), vec_a.end());
    sort(vec_b.begin(), vec_b.end());
    for(const auto& e: vec_a){
        if(!binary_search(vec_b.begin(), vec_b.end(), e)){
            ++sum;
            res.pb(e);
        }
    }
    cout << sum << endl;
    for(const auto& e: res) cout << e << ' ';

    return 0;
}
