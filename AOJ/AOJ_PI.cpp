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

string nums;
int cache[10001];

int classify(int a, int b){
    string M = nums.substr(a, b - a + 1);

    if(M == string(M.size(), M[0])) return 1;
    
    bool progressive = true;

    rep(i, 0, M.size() - 1){
        if(M[i + 1] - M[i] != M[1] - M[0]){
            progressive = false;
            break;
        }
    }
    if(progressive && abs(M[1] - M[0]) == 1) return 2;
    bool alternating = true;

    rep(i, 0, M.size()){
        if(M[i] != M[i % 2]){
            alternating = false;
            break;
        }
    }
    if(alternating) return 4;
    if(progressive) return 5;
    return 10;
}

int memorize(int start = 0){
    if(start == nums.size()) return 0;
    int& ret = cache[start];
    if(ret != -1) return ret;
    ret = INF;
    REP(jump, 3, 5){
        if(start + jump <= nums.size()){
            ret = min(ret, memorize(start + jump) + classify(start, start + jump - 1));
        }
    }
    return ret;
}

int main(){
    FAST;
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    rep(tc, 0, t){
        memset(cache, -1, sizeof(cache));
        cin >> nums;
        cout << memorize() << endl;
    }
    return 0;
}
