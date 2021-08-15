#include <iostream>
#define endl "\n"

using namespace std;

typedef unsigned long long ull;


ull fastMul(ull a, ull b, ull c){
    if(b == 1) return a % c;
    if(b % 2 == 1) return a * fastMul(a, b - 1, c) % c;
    else return fastMul(a, b / 2, c) * fastMul(a, b / 2, c) % c;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ull a, b, c;
    cin >> a >> b >> c;
    cout << fastMul(a, b, c);
    return 0;
}