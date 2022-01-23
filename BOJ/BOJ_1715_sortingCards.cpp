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
    int n, tmp, res = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        q.push(tmp);
    }

    if(n == 1){
        cout << 0;
        return 0;
    }

    while(q.size() > 1){
        int first = q.top(); q.pop();
        int second = q.top(); q.pop();
        res += first + second;
        q.push(first + second);
    }

    cout << res;
    return 0;
}
