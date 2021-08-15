#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define pii pair<int, int>
#define pb push_back
#define INF 987654321

using namespace std;

typedef unsigned long long ull;
vector<ull> arr;

ull solve(int left, int right){
    if(left == right) return 0;
    if(right - left == 1) return arr[left] * arr[right];
    int mid = (left + right) >> 1;

    ull ret = max(solve(left, mid), solve(mid + 1, right));

    int lo = mid, hi = mid + 1;

    ull min_value = min(arr[lo], arr[hi]);
    ull max_value = max(arr[lo], arr[hi]);
    ret = max(ret, min_value * max_value);

    while(left < lo || hi < right){
        if(hi < right && (lo == left || arr[lo - 1] < arr[hi + 1])){
            ++hi;
            min_value = min(min_value, arr[hi]);
            max_value = max(max_value, arr[hi]);
        }else{
            --lo;
            min_value = min(arr[lo], min_value);
            max_value = max(arr[lo], max_value);
        }
        ret = max(ret, min_value * max_value);
    }
    return ret;
}

int main(){
    FAST;
    int t;
    cin >> t;
    rep(tc, 0, t){
        int n;
        cin >> n;
        arr = vector<ull>(n, 0);
        rep(i, 0, n) cin >> arr[i];
        cout << solve(0, n - 1) << endl;
    }
    return 0;
}
