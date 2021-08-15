#include <iostream>
#include <list>
#include <utility>
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int n;
list<pair<int, int> > ball;

inline int abs(int x){
    if(x < 0) return x * (-1);
    return x;
}

void input(){
    cin >> n;
    rep(i, 0, n){
        int tmp;
        cin >> tmp;
        ball.push_back(make_pair(tmp, i + 1));
    }
}

void pop(){
    auto it = ball.begin();
    
    while(ball.size() != 0){
        if(it->first < 0){
            int next = abs(it->first);
            cout << it->second << ' ';
            it = ball.erase(it);
            rep(i, 0, next){
                if(it == ball.begin()){
                    it = ball.end();
                    --it;
                }
                else --it;
            }
        }else{
            int next = it->first;
            cout << it->second << ' ';
            it = ball.erase(it);
            if(it == ball.end()){
                it = ball.begin();
            }
            rep(i, 1, next){
                if(it == ball.end()){
                    it = ball.begin();
                }
                ++it;
            }
            if(it == ball.end()){
                it = ball.begin();
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    pop();
    return 0;
}
// ?