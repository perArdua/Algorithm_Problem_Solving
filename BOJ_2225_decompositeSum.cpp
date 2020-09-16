#include <iostream>
#include <cstring>
#define endl "\n"

using namespace std;
const long long MOD = 1000000000;
int n, k;

long long cache[200][200 * 200]; // cache[picked][total]

long long solve(int picked, int tot){
    if(picked == k) return tot == n ? 1 : 0;

    long long& ret = cache[picked][tot];
    if(ret != -1) return ret;

    ret = 0;
    for(int next = 0; next <= n; ++next){
        ret += solve(picked + 1, tot + next);
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
    long long res = solve(0, 0);
    cout << res << endl;
    //changed
    return 0;
}