#include <iostream>
#include <algorithm>
#define endl "\n"

using namespace std;
const int INF = 987654321;
int n;

// n range 1 ~ 100000

int go(int cnt, int curSum, int picked){
    if(curSum > n) return INF;
    if(curSum == n) return cnt;
    if(picked == 0) return INF;

    int ret = min(go(cnt + 1, curSum + picked * picked, picked), (go(cnt + 1, curSum + picked * picked, picked - 1)));
    ret = min(ret, go(cnt, curSum, picked - 1));
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cout << go(0, 0, n - 1);
    return 0;
}