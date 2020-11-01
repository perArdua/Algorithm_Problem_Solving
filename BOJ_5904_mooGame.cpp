#include <iostream>
#include <vector>
#include <utility>
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
using ull = unsigned long long;

int n;
vector<pair<ull, ull> > lengVec;
int findDepth(ull length = 3, ull center_length = 3){
    if(n <= length) return 1;
    return 1 + findDepth(length * 2 + center_length + 1, center_length + 1);
}

void initVec(){
    int depth = 1;
    int max_depth = findDepth();
    int length = 3;
    int center_length = 4;
    int moo_length = 3;
    while(depth++ <= max_depth){
        lengVec.push_back(make_pair(length, moo_length));
        length = length * 2 + center_length++;
        ++moo_length;
    }
}

char DQ(int vec_index){
    ull leng = lengVec[vec_index].first;
    ull moo_leng = lengVec[vec_index].second;
    ull prev_leng = (leng - moo_leng) / 2;
    if(n < prev_leng){
        return DQ(vec_index - 1);
    }else if(prev_leng + moo_leng <= n){
        n -= prev_leng + moo_leng;
        return DQ(vec_index - 1);
    }else{
        if(n - 1 == prev_leng){
            return 'm';
        }else{
            return 'o';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    initVec();
    cout << DQ(lengVec.size() - 1);
    return 0;
}
// ?