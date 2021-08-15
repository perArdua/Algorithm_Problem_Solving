#include <iostream>
#include <cmath>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

const int INF = 987654321;

int n;
int point[16][2];
double dp[16][1 << 16];
double way_cost[16][16];

inline int min(int a, int b){
    if(a >= b) return b;
    return a;
}

double calDistance(int x1, int y1, int x2, int y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void make_way_cost(){
    rep(i, 0, n){
        rep(j, 0, n){
            if(i == j) continue;
            way_cost[i][j] = calDistance(point[i][0], point[i][1], point[j][0], point[j][1]);
        }
    }
}

double TSP(int cur, int visited){
    if(visited == ((1 << n) - 1)){
        if(way_cost[cur][0]) return way_cost[cur][0];
        return INF;
    }

    double& ret = dp[cur][visited];
    if(ret != 0) return ret;
    ret = INF;
    rep(i, 0, n){
        if(cur == i || visited & (1 << i) || !way_cost[cur][i]) continue;
        ret = min(ret, TSP(i, visited | (1 << i)) + way_cost[cur][i]);
    }
    return ret;
}

int main(){
    FAST;
    cin >> n;
    rep(i, 0, n){
        rep(j, 0, 2){
            cin >> point[i][j];
        }
    }
    make_way_cost();
    cout << fixed;
    cout.precision(6);
    cout << TSP(0, 1) << endl;
    return 0;
}
// ?