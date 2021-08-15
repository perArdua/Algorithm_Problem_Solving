#include <bits/stdc++.h>
#include <iomanip>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>
#define pb push_back
#define INF 987654321.0
#define MAX_CITY 8
using namespace std;

int n, t;
double dist[MAX_CITY][MAX_CITY];
bool visited[MAX_CITY];

double shortestPath(vector<int>& path, double curLeng){
    if(path.size() == n) return curLeng;
    double ret = INF;
    rep(next, 0, n){
        if(visited[next]) continue;
        int here = path.back();
        path.push_back(next);
        visited[next] = true;
        double candi = shortestPath(path, curLeng + dist[here][next]);
        ret = min(ret, candi);
        visited[next] = false;
        path.pop_back();
    }
    return ret;
}

int main(){
    FAST;
    cin >> t;
    rep(tc, 0, t){
        memset(dist, 0, sizeof(dist));
        cin >> n;
        rep(i, 0, n){
            rep(j, 0, n){
                cin >> dist[i][j];
            }
        }
        cout << setprecision(10) << fixed;
        
        double res = INF;
        
        rep(here, 0, n){
            memset(visited, false, sizeof(visited));
            visited[here] = true;
            vector<int> tmp(1, here);
            res = min(res, shortestPath(tmp, 0));
        }

        cout << res << endl;
    }
    return 0;
}
