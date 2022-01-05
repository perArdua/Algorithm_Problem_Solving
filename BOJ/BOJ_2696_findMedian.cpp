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

int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    int t, m, tmp;
    cin >> t;
    while(t--){
        cin >> m;
        vector<int> arr = vector<int>(m);
        priority_queue<int, vector<int>> max_heap;
        priority_queue<int, vector<int>, greater<>> min_heap;

        if(m % 2 == 1) cout << (m / 2) + 1 << endl;
        else cout << m / 2 << endl;

        for(int i = 0; i < m; ++i){
            cin >> tmp;
            min_heap.push(tmp);
            max_heap.push(min_heap.top()); min_heap.pop();
            if(max_heap.size() > min_heap.size()){
                min_heap.push(max_heap.top()); max_heap.pop();
            }
            if(i % 2 == 0){
                cout << min_heap.top() << ' ' ;
            }
        }
        cout << endl;
    }
    return 0;
}
