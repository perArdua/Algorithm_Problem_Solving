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

string src;
vector<string> res;
vector<int> q;
vector<pii> pos;
vector<pii> arr;

void f(int idx){
    if(idx == pos.size()){
        if (pos.size() == arr.size()) return ;
        string ret = "";
        sort(arr.begin(), arr.end(), 
            [] (auto& a, auto& b) -> bool{
                return a.first < b.first;
            }
        );
        auto it = arr.begin();
        vector<int> stack;
        for(int i = 0, j = 0; i < src.size(); ++i){
            if(src[i] != '(' && src[i] != ')'){
                ret.pb(src[i]);
            }else{
                if(it != arr.end() && (*it).first == i){
                    stack.pb((*it++).second);
                    ret.pb(src[i]);
                }else{
                    if(stack.size() && stack.back() == i){
                        ret.pb(src[i]);
                        stack.pop_back();
                    }
                }
            }
        }
        res.pb(ret);
        return ;
    }
    arr.pb(pos[idx]);
    f(idx + 1);
    arr.pop_back();
    f(idx + 1);
}

int main(){
    FAST;
    // freopen("input.txt", "r", stdin);
    cin >> src;
    
    for(int i = 0; i < src.size(); ++i){
        if(src[i] == '('){
            q.pb(i);
        }else if(src[i] == ')'){
            pos.pb(make_pair(q.back(), i)); q.pop_back();
        }
    }
    
    sort(pos.begin(), pos.end(), 
        [] (auto& a, auto& b) -> bool{
            return a.first < b.first;
        }
    );

    f(0);
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    for(auto& s: res) cout << s << endl;
    
    return 0;
}
