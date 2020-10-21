#include <iostream>
#include <cmath>
#define endl "\n"

using namespace std;

int n, r, c;
int cnt = 0;
void recursion(int y, int x, int exp){
    /* basis */
    if(exp == 2){
        if(y == r && x == c){
            cout << cnt << endl;
            return ;
        }
        ++cnt;
        if(y == r && x + 1 == c){
            cout << cnt << endl;
            return ;
        }
        ++cnt;
        if(y + 1 == r && x == c){
            cout << cnt << endl;
            return ;
        }
        ++cnt;
        if(y + 1 == r && x + 1 == c){
            cout << cnt << endl;
            return ;
        }
        ++cnt;
        return ;
    }

    int div = exp / 2;
    recursion(y, x, div);
    recursion(y, x + div, div);
    recursion(y + div, x, div);
    recursion(y + div, x + div, div);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> r >> c;
    recursion(0, 0, (1 << n));
    return 0;
}
// ?