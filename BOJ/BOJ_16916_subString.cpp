#include <bits/stdc++.h>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>
#define pb push_back
#define INF 987654321

using namespace std;

vector<int> makeTable(const string& pattern){
    int patternSize = pattern.size();
    vector<int> ret(patternSize, 0);
    for(int i = 1, j = 0; i < patternSize; ++i){
        while(j > 0 && pattern[i] != pattern[j]){
            j = ret[j - 1];
        }
        if(pattern[i] == pattern[j]){
            ret[i] = ++j;
        }
    }
    return ret;
}

void KMP(const string& org, const string& sub){
    vector<int> table = makeTable(sub);
    int orgSize = org.size();
    int subSize = sub.size();
    for(int i = 0, j = 0; i < orgSize; ++i){
        while(j && org[i] != sub[j]){
            j = table[j - 1];
        }
        if(org[i] == sub[j]){
            if(j + 1 == subSize){
                cout << 1;
                j = table[j];
                return;
            }else{
                ++j;
            }
        }
    }
    cout << 0;
    return;
}

int main(){
    FAST;
    string org, sub;
    cin >> org >> sub;
    KMP(org, sub);
    return 0;
}