#include <iostream>
#include <algorithm>
#include <string>
#define endl "\n"

using namespace std;

int dp[1001][1001];

string s1;
string s2;
/*
LCS(i, j) = LCS(i-1, j-1) + 1 (if, i == j)
LCS(i, j) = max(LCS(i-1, j), LCS(i, j-1)) (if, i != j)
*/
void preCalc(){
    for(int i = 1; i < s1.size(); ++i){ //row 
        for(int j = 1; j < s2.size(); ++j){ //col
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1] + 1; // 좌상 대각방향
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // 좌, 상 방향
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s1 >> s2;
    s1 = to_string(0) + s1;
    s2 = to_string(0) + s2;
    preCalc();   
    cout << dp[s1.size() - 1][s2.size() - 1] << endl;
    return 0;
}