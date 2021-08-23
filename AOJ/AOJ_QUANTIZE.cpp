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

int n, s;
vector<int> sq, pSum, pSqSum;
int cache[1001][11];
void preCalc(){
    pSum[0] = sq[0];
    pSqSum[0] = sq[0] * sq[0];
    rep(i, 1, n){
        pSum[i] = pSum[i - 1] + sq[i];
        pSqSum[i] = pSqSum[i - 1] + sq[i] * sq[i];
    }
}

int minError(int lo, int hi){
    int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
    int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);
    int m = int(0.5 + (double)sum / (hi - lo + 1));

    return sqSum - 2 * m * sum + (hi - lo + 1) * m * m;
}

int quantize(int from, int parts){
    if(from == n) return 0;
    if(parts == 0) return INF;
    int& ret = cache[from][parts];
    if(ret != -1) return ret;
    ret = INF;
    for(int partSize = 1; from + partSize <= n; ++partSize){
        ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
    }
    return ret;
}

int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    rep(tc, 0, t){
        cin >> n >> s;
        sq = vector<int>(n);
        pSum = vector<int>(n);
        pSqSum = vector<int>(n);
        memset(cache, -1, sizeof(cache));
        for(auto& e : sq) cin >> e;
        sort(sq.begin(), sq.end());
        preCalc();
        cout << quantize(0, s) << endl;
    }
    return 0;
}
