#include <iostream>
#define endl "\n"

using namespace std;
char base[][6] = {
            "  *  ",
            " * * ",
            "*****"
            };
char map[3500][7000];
int n;

void fractal(int y, int x, int h){
    if(h == 3){
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 5; ++j){
                map[y + i][x + j] = base[i][j];
            }
        }
        return;
    }
    int div = h / 2;
    
    fractal(y, x + div, div);
    fractal(y + div, x, div);
    fractal(y + div, x + h, div);
}

void output(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 2*n - 1; ++j){
            cout << map[i][j];
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    fill(&map[0][0], &map[0][0] + 3500 * 7000, ' ');
    fractal(0, 0, n);
    output();
    return 0;
}
// ?