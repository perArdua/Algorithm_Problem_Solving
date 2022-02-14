#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define INF 987654321

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool cmp_forward(const list<char>& arr, list<char>::iterator it, const string& dest){
    for(auto i = 0; i < dest.length(); ++i){
        if(it == arr.end()) return false;
        if(*it != dest[i]) return false;
        ++it;
    }
    return true;
}

bool cmp_backward(const list<char>& arr, list<char>::iterator it, const string& dest){
    for(auto i = dest.length() - 1; i != -1; --i){
        if(it == arr.begin()) return false;
        if(*it != dest[i]) return false;
        --it;
    }
    return true;
}

int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    string target, src;
    cin >> target >> src;
    list<char> arr;
    bool progress = true; // true 일 경우 우측 방향으로 src 탐색, false 일 경우 <- 좌측 방향으로 src 탐색
    for(auto& e: src) arr.pb(e);
    arr.push_front('*');
    list<char>::iterator it = arr.begin();
    list<char>::iterator rit = arr.end();

    while(true){
        if(progress){
            if(it == arr.end()) break;
            if(cmp_forward(arr, it, target)){
                for(auto i = 0; i < target.length(); ++i) it = arr.erase(it);
                for(auto i = 0; i < target.length(); ++i){
                    if(it == arr.begin()) break;
                    --it;
                }
                progress = false;
            }else{
                ++it;
            }
        }else{
            if(rit == arr.begin()) break;
            if(cmp_backward(arr, rit, target)){
                for(auto i = 0; i < target.length(); ++i){
                    rit = arr.erase(rit);
                    --rit;
                }
                for(auto i = 0; i < target.length(); ++i){
                    if(rit == arr.end()) break;
                    ++rit;
                }
                progress = true;
            }else{
                --rit;
            }
        }
    }
    arr.pop_front();
    for(auto& e: arr) cout << e;
    return 0;
}
