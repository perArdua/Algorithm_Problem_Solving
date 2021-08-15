#include <iostream>
#include <algorithm>
#define endl "\n"

using namespace std;
int n;
int cache[100000];
// n range 1 ~ 100000

void solve(){
    for(int i = 1; i <= n; ++i) cache[i] = i;
    for(int i = 2; i <= n; ++i){
        for(int j = 2; j * j <= i; ++j){
            cache[i] = min(cache[i], cache[i - j * j] + 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    solve();
    cout << cache[n];
    return 0;
}