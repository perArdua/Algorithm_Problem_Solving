#include <iostream>
#define endl "\n"

using namespace std;

char map[2500][2500];

void star(int y, int x, int num){
    if(num == 3){
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if(i == 1 && j == 1) continue;
                else map[y + i][x + j] = '*';
            }
        }
        return;
    }
    
    int div = num / 3;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(i == 1 && j == 1) continue;
            star(y + i * div, x + j * div, div);
        }
    }
}

void output(int num){
    for(int i = 0; i < num; ++i){
        for(int j = 0; j < num; ++j){
            cout << map[i][j];
        }
        cout << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin >> num;
    fill(&map[0][0], &map[0][0] + 2500 * 2500, ' ');
    star(0, 0, num);
    output(num);
    return 0;
}
