#include <iostream>
#include <vector>
#include <cstring>
#define endl "\n"
#define MAX_ROTATION 4
using namespace std;
int screen[41][41];
vector<vector<pair<int, int> > > stickers(100, vector<pair<int, int>>(100));
int r, c, k;

void makeStickers(){
    int row, col, tmp;
    for(int type = 0; type < k; ++type){
        cin >> row >> col;
        int idx = 0;
        int decideResize = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                cin >> tmp;
                if(tmp){
                    stickers[type][idx].first = i;
                    stickers[type][idx].second = j;
                    ++idx;
                    ++decideResize;
                }
            }
        }
        stickers[type].resize(decideResize + 1);
        stickers[type].back() = make_pair(row, col);
    }
}
int countAttachedStickers(){
    int ret = 0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(screen[i][j]) ++ret;
        }
    }
    return ret;
}
bool inRange(int y, int x){
    return (y >= 0 && y < r) && (x >= 0 && x < c);
}
bool set(const int type, const int delta, const int y, const int x){
    bool ret = true;
    for(int i = 0; i < stickers[type].size() - 1; ++i){ // 맨 마지막에는 해당 스티커의 row, col 정보가 들어 있으므로 이를 제외한다.
        const int ny = y + stickers[type][i].first;
        const int nx = x + stickers[type][i].second;
        if(!inRange(ny, nx)) ret = false; 
        else if((screen[ny][nx] += delta) > 1) ret = false;
    }
    return ret;
}

void rotation(const int type){ // 90도 C.W. 회전
    for(int i = 0; i < stickers[type].size() - 1; ++i){ // 맨 마지막에는 해당 스티커의 row, col 정보가 들어 있으므로 이를 제외한다.
        swap(stickers[type][i].first, stickers[type][i].second);
        stickers[type][i].second = stickers[type].back().first - 1 - stickers[type][i].second;
    }
    swap(stickers[type].back().first, stickers[type].back().second);
}

int cover(){
    for(int type = 0; type < k; ++type){
        bool finished = false;
        for(int rotate = 0; rotate < MAX_ROTATION; ++rotate){

            for(int y = 0; y < r - stickers[type].back().first + 1; ++y){
                for(int x = 0; x < c - stickers[type].back().second + 1; ++x){
                    if(set(type, 1, y, x)){
                        finished = true;
                        break;
                    }else{
                        set(type, -1, y, x);
                    }
                }
                if(finished) break;
            }

            if(finished) break;
            rotation(type);
        }
    }
    return countAttachedStickers();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(screen, 0, sizeof(screen));
    cin >> r >> c >> k;
    makeStickers();
    cout << cover() << endl;
    return 0;
}