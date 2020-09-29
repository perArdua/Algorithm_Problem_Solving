#include <iostream>
#include <vector>
#include <string>
#define endl "\n"

using namespace std;

vector<string> adjustCondition(vector<string>& arr, string& question, int s, int b){
    vector<string> ad;
    for(int i = 100; i <= 999; ++i){
        string tmp = to_string(i);
        if(tmp.find("0") != string::npos) continue;
        if(tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2]) continue;
        int _s = 0, _b = 0;

        for(int j = 0; j < 3; ++j){
            for(int k = 0; k < 3; ++k){
                if(question[j] == tmp[k]){
                    if(j == k) ++_s;
                    else ++_b;
                }
            }
        }
        if(_s == s && _b == b){
            for(string str : arr){
                if(str == tmp) ad.push_back(tmp);
            }
        }
    }
    return ad;
}

void init(vector<string>& arr){
    for(int i = 100; i <= 999; ++i){
        arr[i-100] = to_string(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<string> possible(900);
    init(possible);
    while(n--){
        string candidate; int strike, ball;
        cin >> candidate >> strike >> ball;
        possible = adjustCondition(possible, candidate, strike, ball);
    }
    cout << possible.size() << endl;
    return 0;
}