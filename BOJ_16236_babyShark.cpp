#include <bits/stdc++.h>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>
#define pb push_back
#define INF 987654321

using namespace std;

struct shark{
    int d, y, x;
    bool operator< (const shark& t) const{
        if(d == t.d){
            if (y == t.y) return x > t.x;
            else return y > t.y;
        }else{
            return d > t.d;
        }
    }
};

int n, vol = 2, ate, res = 0;
int a[20][20];
bool visited[20][20];

priority_queue<shark> q;

const int dy[] = {-1, 0, 0, 1};
const int dx[] = {0, -1, 1, 0};

bool inRange(int y, int x){
    return (y >= 0 && y < n) && (x >= 0 && x < n);
}

int main(){
    FAST;
    cin >> n;
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> a[i][j];
            if(a[i][j] == 9){
                q.push({0, i, j});
                a[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        int d = q.top().d, y = q.top().y, x = q.top().x; q.pop();
        if(0 < a[y][x] && a[y][x] < vol){
            a[y][x] = 0;
            
            if(++ate == vol){
                ++vol;
                ate = 0;
            }
            res += d;
            d = 0;
            memset(visited, 0, sizeof(visited));
            while(!q.empty()){
                q.pop();
            }
        }

        rep(dir, 0, 4){
            int ny = y + dy[dir], nx = x + dx[dir];
            if(!inRange(ny, nx)) continue;
            if(visited[ny][nx]) continue;
            if(0 < a[ny][nx] && vol < a[ny][nx]) continue;
            q.push({d + 1, ny, nx});
            visited[ny][nx] = true;
        }
    }
    cout << res;
    return 0;
}
