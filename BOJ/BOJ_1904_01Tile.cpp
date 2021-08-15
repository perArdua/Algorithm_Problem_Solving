#include <iostream>
#include <cstring>
#define endl "\n"

using namespace std;
const int MOD = 15746;
int cache[1000001];

int dp(int n){
    if(n <= 2) return n;
    int& ret = cache[n];
    if(ret != -1) return ret;
    return ret = (dp(n - 1) + dp(n - 2)) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    cout << dp(n) << endl;
    return 0;
}