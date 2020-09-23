#include <iostream>
#include <vector>
#include <cstring>
#include <fstream> // test
#include <string>
#define endl "\n"
#define MAX_ROTATION 4
using namespace std;
int screen[41][41];
vector<vector<pair<int, int> > > stickers(100, vector<pair<int, int>>(100));
int r, c, k;
ofstream out("test.txt"); //test

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
        stickers[type].resize(decideResize);
        stickers[type].push_back(make_pair(row, col));
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
        if(!inRange(ny, nx)) {
            ret = false; 
            out << "(nx, ny) : " + to_string(nx) + " " + to_string(nx) << endl;
        }
        else if((screen[ny][nx] += delta) > 1) ret = false;
    }
    return ret;
}
// range checking이 된다. 만약 -1, -1 페어를 리턴했다는 것은
// 1. out-of-range error 이거나 2. 빈칸을 정말로 못찾았다는 뜻이다.
// case 1, 2 모두 다음 스티커로 넘어가야함을 의미한다.
// pair<int, int> findNextBlank(int y, int x){ 
//     int ry = -1, rx = -1;
//     for(int i = y; i < r; ++i){
//         for(int j = x; j < c; ++j){
//             if(!screen[i][j]){
//                 ry = i, rx = j; break;
//             }
//         }
//         if(ry != -1) break;
//     }
//     return make_pair(ry, rx);
// }

void rotation(const int type){ // 90도 C.W. 회전
    for(int i = 0; i < stickers[type].size() - 1; ++i){ // 맨 마지막에는 해당 스티커의 row, col 정보가 들어 있으므로 이를 제외한다.
        swap(stickers[type][i].first, stickers[type][i].second);
        stickers[type][i].second = stickers[type].back().first - 1 - stickers[type][i].second;
    }
    swap(stickers[type].back().first, stickers[type].back().second);
}


int cover(){
    for(int type = 0; type < k; ++type){
        bool isPasted = false;
        // auto p = findNextBlank(0, 0); // 스티커가 안붙어 있는 칸을 찾는다.
        auto p = make_pair(0, 0);
        while(p.first != -1 && !isPasted){// 스티커가 붙거나, range를 벗어나면 while문을 탈출하여 다음 type을 시도한다
            for(int rotate = 0; rotate < MAX_ROTATION; ++rotate){
                out << "type : " << type << endl;//test start
                out << "rotation : " << rotate << endl;
                out << "Blank ( x, y ) = " << "(" << p.second << ", " << p.first << ")" << endl;
                out << "sticker : " << endl;
                for(int i = 0; i < stickers[type].size() - 1; ++i){
                    out << "(x, y) = " << "(" << stickers[type][i].second << ", " << stickers[type][i].first << ")" << endl;
                }
                for(int i = 0; i < r; ++i){
                    for(int j = 0 ; j < c; ++j){
                        out << screen[i][j] << " ";
                    }
                    out << endl;
                }
                out << endl; // test end
                if(set(type, 1, p.first, p.second)){ //screen에 stkicker를 붙인다.
                    isPasted = true;
                    break;
                }else{
                    set(type, -1, p.first, p.second); // 만약 sticker가 붙지 않았다면 위에 if에서 붙였던 부분을 떼버린다.
                    rotation(type); // 해당 스티커를 회전시킨다.
                }
            }
            if(p.second + 1 < c) p = make_pair(p.first, p.second + 1);
            else p = make_pair(p.first + 1, 0);
            
            if(!inRange(p.first, p.second)) {out << "!inRange executed " + to_string(p.second) + " " + to_string(p.first) << endl; break;}
            // p = findNextBlank(p.first + 1, 0);
        }
    }
    int ret = countAttachedStickers();
    out.close(); //test
    return ret;
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