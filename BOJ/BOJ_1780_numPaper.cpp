#include <iostream>
#include <cmath>
#define endl "\n"

using namespace std;

int n;
int paper[2500][2500];
int first, second, third;

bool isOne(int y, int x, int exp){
    int sheet = paper[y][x];
    for(int i = 0; i < exp; ++i){
        for(int j = 0; j < exp; ++j){
            if(sheet != paper[y + i][x + j]) return false;
        }
    }
    return true;
}

void countAsOne(int y, int x){
    switch (paper[y][x]){
    case -1:
        ++first;
        break;
    case 0:
        ++second;
        break;
    case 1:
        ++third;
        break;
    }
    return;
}

/* this func is invoked when exponential is three  */
void countIndependently(int y, int x){
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            countAsOne(y + i, x + j);
        }
    }
    return;
}

void recursion(int y, int x, int exp){
    if(isOne(y, x, exp)){
        countAsOne(y, x);
        return;
    }else{
        if(exp == 3){
            countIndependently(y, x);
            return;
        }else{
            int div = exp / 3;
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    recursion(y + i * div, x + j * div, div);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> paper[i][j];
        }
    }
    if(n == 1){
        countAsOne(0, 0);
    }else{
        recursion(0, 0, n);
    }
    cout << first << endl;
    cout << second << endl;
    cout << third << endl;
    return 0;
}
// ?