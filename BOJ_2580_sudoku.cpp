#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(auto i = a; i < b; ++i)
#define REP(i, a, b) for(auto i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>

using namespace std;

int board[9][9];
vector<pii> zeros;

void input(){
    rep(i, 0, 9){
        rep(j, 0, 9){
            cin >> board[i][j];
            if(!board[i][j]){
                zeros.push_back({i, j});
            }
        }
    }
}

void output(){
    rep(i, 0, 9){
        rep(j, 0, 9){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

int findBeginNumber(int row_or_col){
    if(row_or_col <= 2) return 0;
    else if(row_or_col <= 5) return 3;
    else if(row_or_col <= 8) return 6;
}
bool checkRow(int row_number, int col_number){
    int& cur_number = board[row_number][col_number];
    rep(col, 0, 9){
        if((cur_number == board[row_number][col]) && (col_number != col)) return false;
    }
    return true;
}
bool checkColumn(int row_number, int col_number){
    int& cur_number = board[row_number][col_number];
    rep(row, 0, 9){
        if((cur_number == board[row][col_number]) && (row_number != row)) return false;
    }
    return true;
}
bool checkSquare(int row_number, int col_number){
    int begin_row = findBeginNumber(row_number);
    int begin_col = findBeginNumber(col_number);
    int& cur_number = board[row_number][col_number];
    rep(i, 0, 3){
        rep(j, 0, 3){
            if((cur_number == board[begin_row + i][begin_col + j]) && ((row_number != begin_row + i) && (col_number != begin_col + j))) return false;
        }
    }
    return true;
}
bool checker(int row_number, int col_number){
    if(checkRow(row_number, col_number) && checkColumn(row_number, col_number) && checkSquare(row_number, col_number)) return true;
    return false;
}

void solve(int idx){
    if(idx == zeros.size()){
        output();
        exit(0);
    }
    REP(candi, 1, 9){
        board[zeros[idx].first][zeros[idx].second] = candi;
        if(checker(zeros[idx].first, zeros[idx].second)){
            solve(idx + 1);
        }
    }
    board[zeros[idx].first][zeros[idx].second] = 0;
    return;
}

int main(void){
    FAST;
    input();
    solve(0);
    return 0;
}