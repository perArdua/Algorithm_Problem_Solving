#include <iostream>
#include <map>
#include <algorithm>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
const int INF = 987654321;
int main(){
    FAST;
    int t;
    cin >> t;
    while(t--){
        map<int, int, greater<int>> Q;
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            char c;
            int tmp;
            cin >> c >> tmp;
            if(c == 'I'){
                if(Q.find(tmp) == Q.end()){
                    Q.insert({tmp, 1});
                }else{
                    ++Q[tmp];
                }
            }else{
                if(!Q.empty()){
                    map<int, int, greater<int>>::iterator it;
                    if(tmp == 1){
                        it = Q.begin();
                    }else{
                        it = --Q.end();
                    }
                    if(--it->second == 0){
                        Q.erase(it);
                    }
                }
            }
        }
        
        if(Q.size() == 0){
            cout << "EMPTY" << endl;
            continue;
        }
        cout << Q.begin() -> first << ' ' <<  (--Q.end()) -> first << endl;
    }
    return 0;
}
// ?