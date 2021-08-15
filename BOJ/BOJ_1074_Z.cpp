#include <iostream>
#include <cmath>
#define endl "\n"

using namespace std;
typedef unsigned long long ull;
ull n, r, c;
ull cnt = 0;
void recursion(ull y, ull x, ull exp){
    /* basis */
    // 3 1 4 -> 19
    if(exp == 2){
        ull delta_row = r - x;
        ull delta_col = c - y;
        if(delta_row && delta_col){
            cnt += 3;
        }else if(delta_col){
            cnt += 1;
        }else if(delta_row){
            cnt += 2;
        }
        cout << cnt << endl;
        return ;
    }
    ull div = exp / 2;
    if(r < div + x && c < div + y){
        recursion(y, x, div);
    }else if(r < div + x && c >= div + y){
        cnt += div * div;
        recursion(y + div, x , div);
    }else if(r >= div + x && c < div + y){
        cnt += 2 * div * div;
        recursion(y, x + div, div);
    }else if (r >= div + x && c >= div + y){
        cnt += 3 * div * div;
        recursion(y + div, x + div, div);
    }
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