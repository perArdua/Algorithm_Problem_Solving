#include <iostream>
#include <cstring>
#define endl "\n"

using namespace std;
const long long MOD = 1000000000;
int n, k;

long long cache[201][201]; // cache[n][k]

long long solve(int curSum, int toPick){
    if(curSum < 0) return 0;
    if(toPick == 1) return 1;
    long long& ret = cache[curSum][toPick];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i <= n; ++i){
        ret += solve(curSum - i, toPick - 1);
        ret %= MOD;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(cache, -1, sizeof(cache));
    cin >> n >> k;
    long long res = solve(n, k);
    cout << res << endl;
    return 0;
}