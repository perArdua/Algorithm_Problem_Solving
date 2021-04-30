#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>
#define INF 987654321

using namespace std;

int col,row;
int box[1001][1001];
queue<pair<int,int> > q;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool inRange(int y,int x){
	return (y>=0 && y<row) && (x>=0 && x<col);
}

int find_max(){
	int ret = -1;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
            if(box[i][j] == 0){
                cout << -1;
                exit(0);
            }
			ret = max(ret,box[i][j]);
		}
	}
	return ret;
}

int solve(){
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int direction = 0; direction<4; direction++){
			int ny = y + dy[direction];
			int nx = x + dx[direction];
			if(!inRange(ny,nx)) continue;
			if(box[ny][nx] == 0){
				box[ny][nx] += box[y][x] + 1;
				q.push(make_pair(ny,nx));
			}
		}
	}
	return find_max() - 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> col >> row;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin >> box[i][j];
			if(box[i][j] == 1){
				q.push(make_pair(i,j));
			}
		}
	}
	cout << solve() << endl;
	return 0;
}