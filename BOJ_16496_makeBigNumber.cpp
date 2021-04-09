#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>

using namespace std;

vector<string> arr;
int n;

void input(){
    bool flag = true;
    cin >> n;
    arr.resize(n);
    rep(i, 0, n){
        cin >> arr[i];
        if(arr[i] != "0") flag = false;
    }
    if(flag){
        cout << 0;
        exit(0);
    }
}

int main(){
    input();
    sort(arr.begin(), arr.end(),
        [](const string& s1, const string& s2){
            return s1 + s2 > s2 + s1;
        }
    );
    rep(i, 0, n) cout << arr[i];
    
    return 0;
}