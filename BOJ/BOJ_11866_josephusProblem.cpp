#include <iostream>
#include <list>
#include <vector>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

int main(){
    FAST;
    int n, k;
    cin >> n >> k;
    list<int> candidate;
    vector<int> res;

    REP(i, 1, n){
        candidate.push_back(i);
    }
    list<int>::iterator it = candidate.begin();
    while(candidate.begin() != candidate.end()){
        if(it == candidate.end()) it = candidate.begin();
        rep(i, 0, k - 1){
            ++it;
            if(it == candidate.end()) it = candidate.begin();
        }
        if(it == candidate.end()) it = candidate.begin();
        res.push_back(*it);
        it = candidate.erase(it);
    }
    cout << '<';
    rep(i, 0, n){
        if(i == n - 1){
            cout << res[i];
            break;
        }
        cout << res[i] << ", ";
    }
    cout << '>';
    return 0;
}
// ?