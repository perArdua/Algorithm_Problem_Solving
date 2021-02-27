#include <iostream>
#include <cstring>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

int n;
int dp[101][10][1<<10];

int recursion(int last_number, int length, int state){
    if(length == n){
        return (state == ((1<<10) - 1)) ? 1 : 0;
    }
    int& ret = dp[length][last_number][state];
    if(ret != -1){
        return ret;
    }
    ret = 0;
    if(last_number - 1 >= 0){
        ret += recursion(last_number - 1, length + 1, state | (1 << (last_number - 1)));
    }
    if(last_number + 1 <= 9){
        ret += recursion(last_number + 1, length + 1, state | (1 << (last_number + 1)));
    }
    ret %= int(1e9);
    return ret;
}

int main(){
    FAST;
    cin >> n;
    int res = 0;
    REP(start, 1, 9){
        memset(dp, -1, sizeof(dp));
        res += recursion(start, 1, 1 << start);
        res %= int(1e9);
    }
    cout << res;
    return 0;
}
