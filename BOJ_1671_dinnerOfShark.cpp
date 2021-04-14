#include <iostream>
#include <vector>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>
#define INF 987654321

using namespace std;

struct Shark{
    int size;
    int speed;
    int intelligence;
    Shark(int _size = 0, int _speed = 0, int _intelligence = 0) : size(_size), speed(_speed), intelligence(_intelligence) {};
};

int n;
vector<Shark> info;
vector<vector<int> > adj;
vector<int> selected;
vector<bool> visited;

void input(){
    cin >> n;
    info.resize(n);
    adj.resize(n);
    selected = vector<int>(n, -1);
    int a, b, c;
    rep(i, 0, n){
        cin >> a >> b >> c;
        info[i] = Shark{a, b, c};
    }
    rep(i, 0, n){
        rep(j, i + 1, n){
            if(info[i].size == info[j].size && info[i].speed == info[j].speed && info[i].intelligence == info[j].intelligence){
                adj[i].push_back(j);
            }
            else if(info[i].size >= info[j].size && info[i].speed >= info[j].speed && info[i].intelligence >= info[j].intelligence){
                adj[i].push_back(j);
            }else if(info[i].size <= info[j].size && info[i].speed <= info[j].speed && info[i].intelligence <= info[j].intelligence){
                adj[j].push_back(i);
            }
        }
    }
}

bool dfs(int here){
    if(visited[here]) return false;
    visited[here] = true;

    for(auto there: adj[here]){
        if(selected[there] == -1 || dfs(selected[there])){
            selected[there] = here;
            return true;
        }
    }
    return false;
}

int bipartiteMatch(){
    int ret = 0;
    rep(i, 0, n){
        rep(j, 0, 2){
            visited = vector<bool>(n, false);
            if(dfs(i)) ++ret;
        }
    }
    return ret;
}

int main(){
    FAST;
    input();
    cout << n - bipartiteMatch();
    return 0;
}