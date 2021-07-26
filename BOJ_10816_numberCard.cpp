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

int lower_bound(vector<int>& a, int target){
    int lo = 0;
    int hi = a.size();
    while(lo < hi){
        int mid = (lo + hi) >> 1;
        if(a[mid] >= target) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int upper_bound(vector<int>& a, int target){
    int lo = 0;
    int hi = a.size();
    while(lo < hi){
        int mid = (lo + hi) >> 1;
        if(a[mid] > target) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}


int main(){
    FAST;
    int n, m;
    cin >> n;
    vector<int> src(n);
    rep(i, 0, n) cin >> src[i];
    sort(src.begin(), src.end());
    cin >> m;
    vector<int> dest(m);
    rep(i, 0, m) cin >> dest[i];
    for(auto& e : dest){
        cout << upper_bound(src, e) - lower_bound(src, e) << ' ';
    }
    return 0;
}