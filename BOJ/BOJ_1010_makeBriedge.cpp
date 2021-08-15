#include <iostream>
#include <cstring>
#define endl "\n"

using namespace std;
int cache[31][31];

/*
좌측에서 우측으로 즉 N에 대응 되는 M을 계산하려고 하니 비슷한 동작을 
수행하는 재귀함수를 또 만들어야 하는 번거로움이 있었다.
문제를 단순화 하기 위해서 우측에서 좌측으로 즉 M에 대응 되는 N을 선택하면
교차되는지 여부의 관계 없이, 그 경우는 반드시 1가지이다. (자동배치)
즉 우리는 mCn을 계산하면 문제의 정답을 구할 수 있다.
*/
int preCalc(int n, int m){
    if(n == m || m == 0) return 1;
    int& ret = cache[n][m];
    if(ret != -1) return ret;
    return ret = preCalc(n-1, m-1) + preCalc(n-1, m);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(cache, -1, sizeof(cache));
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m; // 0 < n <= m < 30
        cout << preCalc(m, n) << endl;

    }

    return 0;
}

