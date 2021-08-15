#include <iostream>
#include <vector>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>
#define INF 987654321


using namespace std;

int n, max_row, max_col;
vector<vector<int> > adj;
vector<bool> visited;
vector<int> selected;


void numberingRow(vector<vector<int> >& board, vector<vector<int> >& row){
    int cnt = 1;
    bool is_changed;
    rep(i, 0, n){
        is_changed = false;
        rep(j, 0, n){
            if(board[i][j] == 0){
                row[i][j] = cnt;
                is_changed = true;
            }else{
                if(is_changed){
                    ++cnt;
                    is_changed = false;
                }
            }
        }
        if(is_changed){
            ++cnt;
        }
    }
    max_row = --cnt;
}

void numberingCol(vector<vector<int> >& board, vector<vector<int> >& col){
    int cnt = 1;
    bool is_changed;
    rep(i, 0, n){
        is_changed = false;
        rep(j, 0, n){
            if(board[j][i] == 0){
                col[j][i] = cnt;
                is_changed = true;
            }else{
                if(is_changed){
                    ++cnt;
                    is_changed = false;
                }
            }
        }
        if(is_changed){
            ++cnt;
        }
    }
    max_col = --cnt;
}

void numbering(vector<vector<int> >& board, vector<vector<int> >& row, vector<vector<int> >& col){
    numberingRow(board, row);
    numberingCol(board, col);
}

void makeAdj(vector<vector<int> >& row, vector<vector<int> >& col){
    adj = vector<vector<int> >(max_row + 1);
    rep(i, 0, n){
        rep(j, 0, n){
            adj[row[i][j]].push_back(col[i][j]);
        }
    }
}

int dfs(int here){
    if(visited[here]) return false;
    visited[here] = true;
    
    for(int there: adj[here]){
        if(selected[there] == -1 || dfs(selected[there])){
            selected[there] = here;
            return true;
        }
    }
    return false;
}

void bipartiteMatch(){
    int res = 0;
    selected = vector<int>(max_col + 1, -1);
    REP(i, 1, max_row){
        visited = vector<bool> (max_row + 1, false);
        if(dfs(i)) ++res;
    }
    cout << res;
}

void input(){
    cin >> n;
    vector<vector<int> > board(n, vector<int>(n, 0));
    vector<vector<int> > row(n, vector<int>(n, 0));
    vector<vector<int> > col(n, vector<int>(n, 0));
    char tmp;
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> tmp;
            if(tmp == 'X'){
                board[i][j] = 1;
            }
        }
    }
    numbering(board, row, col);
    makeAdj(row, col);
}

int main(){
    FAST;
    input();
    bipartiteMatch();
    return 0;
}  