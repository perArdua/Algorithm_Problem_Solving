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

const int CLOCKS = 16, SWITCHES = 10;

vector<string> linked {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

vector<int> clocks(CLOCKS);

bool areAligned(){
    rep(cur, 0, CLOCKS){
        if(clocks[cur] != 12) return false;
    }
    return true;
}

void push(int swtch){
    rep(i, 0, CLOCKS){
        if(linked[swtch][i] == 'x'){
            clocks[i] += 3;
            if(clocks[i] == 15) clocks[i] = 3;
        }
    }
}

int solve(int swtch){
    if(swtch == SWITCHES) return areAligned() ? 0 : INF;
    int ret = INF;
    rep(push_cnt, 0, 4){
        ret = min(ret, push_cnt + solve(swtch + 1));
        push(swtch);
    }
    return ret;
}

int main(){
    FAST;
    int t;
    cin >> t;
    rep(tc, 0, t){
        rep(i, 0, CLOCKS) cin >> clocks[i];
        int res = solve(0);
        if(res != INF) cout << res << endl;
        else cout << -1 << endl;
    }
    return 0;
}

