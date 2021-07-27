#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>
#define pb push_back
#define INF 987654321

using namespace std;

string solve(string::iterator& it){
    char head = *it++;
    if(head == 'b' || head == 'w'){
        return string(1, head);
    }
    string upperLeft = solve(it);
    string upperRight = solve(it);
    string lowerLeft = solve(it);
    string lowerRight = solve(it);
    return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(){
    FAST;
    int t;
    cin >> t;
    rep(tc, 0, t){
        string s;
        cin >> s;
        string::iterator iter= s.begin();
        cout << solve(iter) << endl;
    }

    return 0;
}