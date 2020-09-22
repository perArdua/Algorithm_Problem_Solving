#include <iostream>
#include <vector>
#include <cstring>
#include <fstream> // test
#define endl "\n"
#define MAX_ROTATION 4
using namespace std;
int screen[40][40];
vector<vector<pair<int, int> > > stickers(100, vector<pair<int, int>>(10));
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
        stickers[type].resize(decideResize);
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
bool set(int type, int delta, int y, int x){
    bool ret = true;
    for(int i = 0; i < stickers[type].size(); ++i){
        const int ny = stickers[type][i].first;
        const int nx = stickers[type][i].second;
        if(!inRange(ny, nx)) ret = false;
        else if((screen[ny][nx] += delta) > 1) ret = false;
    }
    return ret;
}
// range checking이 된다. 만약 -1, -1 페어를 리턴했다는 것은
// 1. out-of-range error 이거나 2. 빈칸을 정말로 못찾았다는 뜻이다.
// case 1, 2 모두 다음 스티커로 넘어가야함을 의미한다.
pair<int, int> findNextBlank(int y, int x){ 
    int ry = -1, rx = -1;
    for(int i = y; i < r; ++i){
        for(int j = x; j < c; ++j){
            if(!screen[i][j]){
                ry = i, rx = j; break;
            }
        }
        if(ry != -1) break;
    }
    return make_pair(ry, rx);
}
// void rotation(){
//     int tmp[40][40];
//     for(int i = 0; i < r; ++i){
//         for(int j = 0; j < c; ++j){
//             tmp[i][j] = screen[i][j];
//         }
//     }
//     for(int i = 0; i < c; ++i){
//         for(int j = 0; j < r; ++j){
//             screen[i][j] = tmp[r -1 - j][i];
//         }
//     }
//     swap(r, c);
// }
// r = 3, c = 4
// 20 -> 00
// 12 -> 21
// 03 -> 32
// 02 -> 22
// cal col = abs(r - storedValue)
// 11 -> 11
void rotation(int type){
    for(int i = 0; i < stickers[type].size(); ++i){
        int tmpY = stickers[type][i].first;
        int tmpX = stickers[type][i].second;
        stickers[type][i].second = tmpX;
        stickers[type][i].first = abs(r - 1 - tmpY);
    }
    // swap(r, c);

}


int cover(){
    ofstream out("test.txt"); //test
    for(int type = 0; type < k; ++type){
        bool isPasted = false;
        auto p = findNextBlank(0, 0);
        while(p.first != -1 && !isPasted){
            for(int rotate = 0; rotate < MAX_ROTATION; ++rotate){
                out << "type : " << type << endl;
                out << "rotation : " << rotate << endl;
                out << "Blank ( x, y ) = " << "(" << p.second << ", " << p.first << ")" << endl;
                out << "sticker : " << endl;
                for(int i = 0; i < stickers[type].size(); ++i){
                    out << "(x, y) = " << "(" << stickers[type][i].second << ", " << stickers[type][i].first << ")" << endl;
                }
                for(int i = 0; i < r; ++i){//test s
                    for(int j = 0 ; j < c; ++j){
                        out << screen[i][j] << " ";
                    }
                    out << endl;
                }
                out << endl; // test e
                if(set(type, 1, p.first, p.second)){
                    isPasted = true;
                    break;
                }else{
                    set(type, -1, p.first, p.second);
                    rotation(type);
                }
            }
            p = findNextBlank(p.first, p.second + 1);
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