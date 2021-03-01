#include <iostream>
#include <cstring>
#include <string>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

int n, p, cur_status = 0;
int map[20][20];
int cache[1<<17];
const int INF = 987654321;
string str;

inline int min(int a, int b){
    if(a >= b) return b;
    return a;
}

bool cal_bit_on(int bits){
    int res = 0;
    while(bits){
        res += bits & 1;
        bits >>= 1;
    }
    return res >= p ? true : false;
}

int solve(int state){
    if(cal_bit_on(state)){
        return 0;
    }
    int& ret = cache[state];
    if(ret != -1) return ret;
    ret = INF;
    rep(on, 0, n){
        if(!(state & (1 << on))) continue;
        rep(off, 0, n){
            if(state & (1 << off)) continue;
            ret = min(ret, solve(state | (1 << off)) + map[on][off]);
        }
    }
    return ret;
}

void input(){
    cin >> n;
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> map[i][j];
        }
    }
    cin >> str;
    cin >> p;
}

void updateCurStatus(){
    for(int i = 0; i < str.length(); ++i){
        if(str[i] == 'Y'){
            cur_status |= (1 << i);
        }
    }
}

int main(){
    FAST;
    memset(cache, -1, sizeof(cache));
    input();
    updateCurStatus();
    int res = solve(cur_status);
    if(res >= INF) cout << -1;
    else cout << res;
    return 0;

}
// ?
