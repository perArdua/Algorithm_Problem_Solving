#include <iostream>
#define endl "\n"

using namespace std;

char map[1024][1024];

void recursion(int y, int x, int exp){
    if(exp == 1){
        map[y][x] = '*';
        return ;
    }
    int div = exp / 2;

    recursion(y, x, div);
    recursion(y + div, x, div);
    recursion(y, x + div, div);
}

void output(int n){
    int k = (1 << n);
    for(int i = 0; i < (1 << n); ++i, --k){
        for(int j = 0; j < k; ++j){
            cout << map[i][j];
        }
        if(i != (1 << n) - 1) cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(&map[0][0], &map[0][0] + 1024 * 1024, ' ');
    int n;
    cin >> n;
    recursion(0, 0, 1 << n);
    output(n);
    return 0;
}