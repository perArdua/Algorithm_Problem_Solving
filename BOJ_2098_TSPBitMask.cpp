#include <iostream>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

int n;
int way[16][16];
int cache[16][1<<16];

const int INF = 987654321;

int TSP(int cur, int visited){
    if(visited == (1 << n) - 1){
        if(way[cur][0]) return way[cur][0];
        else return INF;
    }
    int &ret = cache[cur][visited];

    if(ret != 0) return ret;
    
    ret = INF;
    rep(next, 0, n){
        if((visited & (1 << next)) || (!way[cur][next])) continue;
        ret = min(ret, (TSP(next, visited | (1 << next))) + way[cur][next]) ;
    }
    return ret;
}

int main(){
    FAST;
    cin >> n;
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> way[i][j];
        }
    }
    cout << TSP(0, 1);
    return 0;
}
// ?