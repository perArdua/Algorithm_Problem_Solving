#include <iostream>
#include <cstring>
#define endl "\n"

using namespace std;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
char area[100][100];
bool check[100][100];
int n;

enum class category{red_green_ok, red_green_not_ok};

void dfs(const int y, const int x, const category which_one){
    check[y][x] = true;

    for(int dir = 0; dir < 4; ++dir){
        const int ny = y + dy[dir];
        const int nx = x + dx[dir];
        if(!((ny >= 0 && ny < n) && (nx >= 0 && nx < n))) continue;
        if(check[ny][nx]) continue;

        if(which_one == category::red_green_not_ok){
            if(area[y][x] == 'R' || area[y][x] == 'G'){ // 현 좌표가 R or G이면  // constrapositive = not R and not G
                if(area[ny][nx] == 'R' || area[ny][nx] == 'G'){ // 다음 좌표가 R or G이어야 한다
                    dfs(ny, nx, category::red_green_not_ok); // 맞을 경우 다음 좌표를 dfs한다.
                }
            }
            else{
                if(area[ny][nx] == area[y][x]) dfs(ny, nx, category::red_green_not_ok); //현 좌표가 B이면 다음 좌표도 B이어야 한다.
            }
        }
        else if(which_one == category::red_green_ok){
            if(area[ny][nx] == area[y][x]) dfs(ny, nx, category::red_green_ok);
        }
    }
    return;
}

int switchCase(const category which_one){
    int ret = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(!check[i][j]){
                dfs(i, j, which_one);
                ++ret;
            }
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> area[i][j];
        }
    }
    cout << switchCase(category::red_green_ok) << " ";
    memset(check, false, sizeof(check));
    cout << switchCase(category::red_green_not_ok);
    return 0;
}