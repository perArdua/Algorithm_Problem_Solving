#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#define endl "\n"

using namespace std;

struct Point{
    short x, y;
};

int n;
vector<Point> convenienceStore;
bool check[100];


void bfs(const Point& home, const Point& dest){
    bool isAnswer = false;
    queue<Point> q;
    q.push(home);
    while(!isAnswer && !q.empty()){
        Point curPos = q.front(); q.pop();
        for(int i = 0; i < convenienceStore.size(); ++i){
            if(check[i]) continue;
            if(abs(curPos.x - convenienceStore[i].x) + abs(curPos.y - convenienceStore[i].y) <= 1000){
                q.push(convenienceStore[i]);
                check[i] = true;
            }
        }

        if(abs(curPos.x - dest.x) + abs(curPos.y - dest.y) <= 1000){
            isAnswer = true;
            break;
        }
    }
    if(isAnswer) cout << "happy" << endl;
    else cout << "sad" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        Point home, dest;
        cin >> home.x >> home.y;
        for(int i = 0; i < n; ++i){
            convenienceStore.push_back(Point());
            cin >> convenienceStore[i].x >> convenienceStore[i].y;
        }
        convenienceStore.resize(n);
        cin >> dest.x >> dest.y;
        bfs(home, dest);
        convenienceStore.clear();
        memset(check, false, sizeof(check));
    }
    return 0;
}