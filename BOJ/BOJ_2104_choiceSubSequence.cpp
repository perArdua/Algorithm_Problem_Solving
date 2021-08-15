#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)

using namespace std;
using ull = unsigned long long;

int n;
vector<ull> sequence;

void input(){
    cin >> n;
    sequence.reserve(n);
    rep(i, 0, n) cin >> sequence[i];
}

ull DQ(int left, int right){
    if(left == right) return sequence[left] * sequence[left];
    int mid = (left + right) / 2;
    ull ret = max(DQ(left, mid), DQ(mid + 1, right));
    int lo = mid, hi = mid + 1;
    ull mul_operand = min(sequence[lo], sequence[hi]);
    ull cur_sum = sequence[lo] + sequence[hi];
    ret = max(ret, mul_operand * cur_sum);
    while(left < lo || hi < right){
        if(hi < right && (lo == left || sequence[lo - 1] < sequence[hi + 1])){
            mul_operand = min(mul_operand, sequence[hi + 1]);
            cur_sum += sequence[hi + 1];
            ret = max(ret, cur_sum * mul_operand);
            ++hi;
        }else{
            mul_operand = min(mul_operand, sequence[lo - 1]);
            cur_sum += sequence[lo - 1];
            ret = max(ret, cur_sum * mul_operand);
            --lo;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    cout << DQ(0, n - 1);
    return 0;
}
// ?