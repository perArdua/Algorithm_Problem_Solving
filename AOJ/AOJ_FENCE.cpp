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

int solve(vector<int>& arr, int left, int right){
    if(left == right) return arr[left];
    int mid = (left + right) >> 1;
    int ret = max(solve(arr, left, mid), solve(arr, mid + 1, right));

    int lo = mid, hi = mid + 1;
    int height = min(arr[lo], arr[hi]);
    ret = max(ret, 2 * height);

    while(left < lo || hi < right){
        if(hi < right && (left == lo || arr[lo - 1] < arr[hi + 1])){
            height = min(height, arr[++hi]);
        }else{
            height = min(height, arr[--lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int solve(vector<int>& arr){
    return solve(arr, 0, arr.size() - 1);
}

int main(){
    FAST;
    int t;
    cin >> t;
    rep(tc, 0, t){
        int n;
        cin >> n;
        vector<int> fence(n);
        rep(i, 0, n) cin >> fence[i];
        cout << solve(fence) << endl;
    }
    return 0;
}