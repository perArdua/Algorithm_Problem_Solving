#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(auto i = a; i < b; ++i)
#define REP(i, a, b) for(auto i = a; i <= b; ++i)
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define INF 987654321

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
int board[32][32];
ll cache[32][32][3];

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T& val){
    fill((T*)array, (T*)(array + N), val);
}

int can_move(int y, int x){
    return (y >= 0 && y < n) && (x >= 0 && x < n) && (!board[y][x]);
}

ll move(int y, int x, int cur_state){
    if((y == n - 1) && (x == n - 1)) return 1;
    
    ll& ret = cache[y][x][cur_state];
    if(ret != -1) return ret;

    ret = 0;

    if(cur_state == 0){
        if(can_move(y, x + 1)){
            ret += move(y, x + 1, 0);
        }
        if(can_move(y, x + 1) && can_move(y + 1, x) && can_move(y + 1, x + 1)){
            ret += move(y + 1, x + 1, 1);
        }
    }else if(cur_state == 1){
        if(can_move(y, x + 1)){
            ret += move(y, x + 1, 0);
        }
        if(can_move(y, x + 1) && can_move(y + 1, x) && can_move(y + 1, x + 1)){
            ret += move(y + 1, x + 1, 1);
        }
        if(can_move(y + 1, x)){
            ret += move(y + 1, x, 2);
        }
    }else if(cur_state == 2){
        if(can_move(y + 1, x)){
            ret += move(y + 1, x, 2);
        }
        if(can_move(y, x + 1) && can_move(y + 1, x) && can_move(y + 1, x + 1)){
            ret += move(y + 1, x + 1, 1);
        }
    }

    return ret;
}

int main(){
    FAST;
#ifndef ONLINE_JUDGE
    clock_t start = clock();
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;
    rep(i, 0, n) rep(j, 0, n) cin >> board[i][j];
    Fill(cache, static_cast<ll>(-1));

    cout << move(0, 1, 0);
#ifndef ONLINE_JUDGE
    cout << endl;
    cout << "elapsed time: " << static_cast<double>(clock() - start) / CLOCKS_PER_SEC << "ms" << endl;
#endif

    return 0;
}
