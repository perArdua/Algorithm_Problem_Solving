#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define INF 987654321

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int indexing[100'001];

int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    int n, p, l, m;
    string tmp;

    auto cmp = [](const pii& a, const pii& b) {
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second > b.second;
    };

    set<pii, decltype(cmp)> pq(cmp);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> p >> l;
        pq.insert({p, l});
        indexing[p] = l;
    }

    cin >> m;
    while(m--){
        cin >> tmp;
        if(tmp == "solved"){
            cin >> p;
            pq.erase({p, indexing[p]});
        }else if(tmp == "recommend"){
            cin >> p;
            if(p == 1){
                cout << (*pq.begin()).first << endl;
            }else{
                cout << (*pq.rbegin()).first << endl;
            }
        }else{
            cin >> p >> l;
            pq.insert({p, l});
            indexing[p] = l;
        }
    }

    return 0;
}
