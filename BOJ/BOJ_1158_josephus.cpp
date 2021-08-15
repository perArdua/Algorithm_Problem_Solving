#include <iostream>
#include <list>
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int n, k;

list<int> candidate;
list<int> sequence;

void initList(){
    rep(i, 1, n + 1){
        candidate.push_back(i);
    }
}

void killingSpree(){
    initList();
    auto kill = candidate.begin();
    rep(i, 0, k - 1) {++kill;}
    cout << '<';
    while(true){
        if(n == 1){
            cout << *kill;
            break;
        }
        cout << *kill << ", ";
        kill = candidate.erase(kill);
        if(kill == candidate.end()) kill = candidate.begin();
        --n;
        rep(i, 0, k - 1){
            ++kill;
            if(kill == candidate.end()) kill = candidate.begin();
        }
    }
    cout << '>';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    killingSpree();
    return 0;
}
// ?