#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
typedef pair<int, int> pi;
constexpr int INF = 987654321;
int n;

void input(vector<pi>& p){
    rep(i, 0, n){
        int a, b;
        cin >> a >> b;
        p[i].first = a;
        p[i].second = b;
    }
    sort(p.begin(), p.end());
    return;
}

int sweeping(vector<pi>& p){
    int res = 0, start = p[0].first, end = p[0].second;
    bool flag;
    rep(i, 0, n){
        if(p[i].first < end){
            end = max(end, p[i].second);
        }else{
            res += end - start;
            start = p[i].first;
            end = p[i].second;
        }
    }
    res += end - start;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<pi> point(n);
    input(point);
    cout << sweeping(point);
    return 0;
}
// ?