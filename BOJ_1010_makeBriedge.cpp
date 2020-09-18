#include <iostream>
#include <cstring>
#define endl "\n"

using namespace std;
int cache[30][30];
/*
m개중 맨 위의 1개를 선택했다면 나머지 m-1개에서 n-1개를 선택한다
n-1 C r-1 + n-1 C r
*/
int preCalc(int n, int m){
    if(n == m || m == 0) return 1;
    int& ret = cache[n][m];
    if(ret != -1) return ret;
    return ret = preCalc(n-1, m-1) + preCalc(n-1, m);
}

int solve(int n, int m){
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(cache, -1, sizeof(cache));
    int t;
    while(t--){
        int n, m;
        cin >> n >> m; // 0 < n <= m < 30
        solve(n, m);

    }

    return 0;
}

