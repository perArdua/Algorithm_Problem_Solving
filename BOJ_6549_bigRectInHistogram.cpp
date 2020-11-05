#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
using ull = unsigned long long;

int n;
vector<ull> heights;

void input();

ull DQ(int left, int right){
    if(left == right) return heights[left];
    int mid = (left + right) / 2;
    ull ret = max(DQ(left, mid), DQ(mid + 1, right));
    int lo = mid , hi = mid + 1;
    ull min_height = min(heights[lo], heights[hi]);
    ret = max(ret, 2 * min_height);
    while(left < lo || hi < right){
        if(hi < right && (lo == left || heights[lo - 1] < heights[hi + 1])){
            ++hi;
            min_height = min(min_height, heights[hi]);
        }else{
            --lo;
            min_height = min(min_height, heights[lo]);
        }
        ret = max(ret, min_height * (hi - lo + 1));
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    n = heights[0];
    while(n != 0){
        cout << DQ(1, n) << endl;
        input();
        n = heights[0];
    }
    return 0;
}
// ?
void input(){
    string str;
    getline(cin, str);
    string tmp = "";
    heights.clear();
    for(int i = 0; i < str.length(); ++i){
        tmp += str[i];
        if(str[i] == ' ' || i == str.length() - 1){
            heights.push_back(stoi(tmp));
            tmp = "";
        }
    }
}