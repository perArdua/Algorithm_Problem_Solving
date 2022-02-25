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

vector<vector<int>> jungle(1001, vector<int>(1001, 0));
vector<vector<int>> ocean(1001, vector<int>(1001, 0));
vector<vector<int>> ice(1001, vector<int>(1001, 0));
int n, m, k;

int grid_sum(const vector<vector<int>>& vec, int y1, int x1, int y2, int x2){
    int ret = vec[y2][x2];
    if(y1 > 0) ret -= vec[y1 - 1][x2];
    if(x1 > 0) ret -= vec[y2][x1 - 1];
    if(y1 > 0 && x1 > 0) ret += vec[y1 - 1][x1 - 1];
    return ret;
}

int main(){
    FAST;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    char tmp;
    cin >> n >> m >> k;

    REP(i, 1, n){
        REP(j, 1, m){
            cin >> tmp;
            switch (tmp){
            case 'J':
                ++jungle[i][j];
                break;

            case 'O':
                ++ocean[i][j];
                break;

            case 'I':
                ++ice[i][j];
                break;
            
            default:
                cout << "ERROR" << endl;
                return 0;
            }
            jungle[i][j] = jungle[i - 1][j] + jungle[i][j - 1] - jungle[i - 1][j - 1] + jungle[i][j];
            ocean[i][j] = ocean[i - 1][j] + ocean[i][j - 1] - ocean[i - 1][j - 1] + ocean[i][j];
            ice[i][j] = ice[i - 1][j] + ice[i][j - 1] - ice[i - 1][j - 1] + ice[i][j];
        }
    }

    int a, b, c, d;

    rep(i, 0, k){
        cin >> a >> b >> c >> d;
        cout << grid_sum(jungle, a, b, c, d) << ' ' << grid_sum(ocean, a, b, c, d) << ' ' << grid_sum(ice, a, b, c, d) << endl;
    }

    return 0;
}
