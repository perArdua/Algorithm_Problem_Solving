#include <iostream>
#include <string>
#include <vector>
#define endl "\n"

using namespace std;

int n;
vector<string> src;
string answer;

void input(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        string tmp;
        cin >> tmp;
        src.push_back(tmp);
    }
}

bool isOne(int y, int x, int div){
    char s = src[y][x];
    for(int i = 0; i < div; ++i){
        for(int j = 0; j < div; ++j){
            if(s != src[y + i][x + j]) return false;
        }
    }
    return true;
}

void recursion(int y, int x, int exp){
    /* basis 1 : exp == 1 */
    if(exp == 1 || isOne(y, x, exp)){
        answer.push_back(src[y][x]);
        return;
    }else{
        int div = exp / 2;
        bool flag = false;
        answer.push_back('(');
        for(int i = 0 ; i < 2; ++i){
            for(int j = 0; j < 2; ++j){
                recursion(y + i * div, x + j * div, div);
            }
        }
        answer.push_back(')');
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    recursion(0, 0, n);
    cout << answer << endl;
    return 0;
}
// ?