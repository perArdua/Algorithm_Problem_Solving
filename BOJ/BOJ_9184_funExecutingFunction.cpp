#include <iostream>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

int d[21][21][21];

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    else if(a > 20 || b > 20 || c > 20){
        return w(20, 20, 20);
    }
    int& ret = d[a][b][c];
    if(ret != 0) return ret;
    else if(a < b && b < c){
        return ret = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }else{
        return ret = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }

}

int main(){
    FAST;
    while(1){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1){
            exit(0);
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }
    return 0;
}
// ?