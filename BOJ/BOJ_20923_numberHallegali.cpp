#include <bits/stdc++.h>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>
#define INF 987654321

using namespace std;

const string dodo_win = "do";
const string su_win = "su";

int main(){
    FAST;
    int n, m, cnt = 0, flag = 1;
    int u, v;
    cin >> n >> m;
    deque<int> dodo, su, dodo_g, su_g;
    
    rep(i, 0, n){
        cin >> u >> v;
        dodo.push_back(u);
        su.push_back(v);
    }

    while (m--){
        if(flag){
            dodo_g.push_back(dodo.back());
            dodo.pop_back();
            if (dodo.empty()){
                cout << su_win;
                return 0;
            }
        }else{
            su_g.push_back(su.back());
            su.pop_back();
            if (su.empty()){
                cout << dodo_win;
                return 0;
            }
        }
        flag ^= 1;
        if (!su_g.empty() && !dodo_g.empty() && ((su_g.back() + dodo_g.back()) == 5)){
            while (!dodo_g.empty()){
                su.push_front(dodo_g.front());
                dodo_g.pop_front();
            }
            while (!su_g.empty()){
                su.push_front(su_g.front());
                su_g.pop_front();
            }
        }

        else if ((!dodo_g.empty() && dodo_g.back() == 5) || (!su_g.empty() && (su_g.back() == 5))){
            while (!su_g.empty()){
                dodo.push_front(su_g.front());
                su_g.pop_front();
            }
            while (!dodo_g.empty()){
                dodo.push_front(dodo_g.front());
                dodo_g.pop_front();
            }
        }
        
    }

    if (dodo.size() == su.size()){
        cout << dodo_win + su_win;
    }
    else if (dodo.size() > su.size()){
        cout << dodo_win;
    }
    else{
        cout << su_win;
    }
    return 0;
}