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

int n, m;
int cache[101][101];
const ll NEGINF = numeric_limits<ll>::min();

vector<int> A;
vector<int> B;

int jlis(int indexA, int indexB){
    int& ret = cache[indexA + 1][indexB + 1];
    if(ret != -1) return ret;
    ret = 2;

    ll a = (indexA == -1 ? NEGINF : A[indexA]);
    ll b = (indexB == -1 ? NEGINF : B[indexB]);

    ll maxElement = max(a, b);

    rep(nextA, indexA + 1, n){
        if(maxElement < A[nextA]){
            ret = max(ret, 1 + jlis(nextA, indexB));
        }
    }
    rep(nextB, indexB + 1, m){
        if(maxElement < B[nextB]){
            ret = max(ret, 1 + jlis(indexA, nextB));
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
        cin >> n >> m;
        A = vector<int> (n);
        B = vector<int> (m);
        for(auto& e : A) cin >> e;
        for(auto& e : B) cin >> e;
        cout << jlis(-1, -1) - 2<< endl;
    }
    return 0;
}
