#include <iostream>

#define endl "\n"

using namespace std;
const long long MOD = 1000000000;
int n, k;

long long solve(int cur, int picked, int tot){
    if(picked == k) return tot == n ? 1 : 0;
    long long ret = 0;
    for(int next = 0; next <= n; ++next){
        ret += ((solve(next, picked + 1, tot + next) % MOD) + 
                (solve(cur, picked + 1, tot + cur) % MOD)) % MOD;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    long long res = solve(0, 0, 0);
    cout << res << endl;
    return 0;
}