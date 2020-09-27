#include <iostream>
#include <string>
#include <limits>
#include <vector>
#define endl "\n"

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> ans(10000);
    for(int i =666; i <= numeric_limits<int>::max(); ++i){
        if(to_string(i).find("666") != string::npos){
            cnt += 1;
            ans[cnt - 1] = i;
        }
        if(cnt == n){
            cout << ans[n - 1] << endl;
            return 0;
        }
    }
    return 0;
}