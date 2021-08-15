#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define Min(X, Y) ((X) < (Y) ? (X) : (Y))
#define Max(X, Y) ((X) > (Y) ? (X) : (Y))
#define pii pair<int, int>
#define pb push_back
#define INF 987654321

using namespace std;

void normalize(vector<int>& num); // num 자릿수 올림 처리
vector<int> multiply(const vector<int>& a, const vector<int>& b); // 자릿수 작은 숫자의 곱
void addTo(vector<int>& a, const vector<int>& b, int k); // a += b * (10 ^ k)
void subFrom(vector<int>& a, const vector<int>& b); // a -= b (a >= b)
vector<int> karatsuba(const vector<int>& a, const vector<int>& b);
void printAll(const vector<int>& a);

int main(){
    FAST;
    vector<int> randNum1 {7, 6, 6, 1, 3, 9, 5, 2, 5, 6, 8, 6, 8, 3, 7, 8, 9, 7, 9, 7, 5, 9, 1, 6, 0, 9, 8, 9, 1, 7, 7, 9, 8, 9, 5, 5, 0, 8, 8, 3, 0, 4, 8, 5, 2, 0, 0, 1, 9, 6, 5, 4, 0, 8, 9};
    vector<int> randNum2 {8, 3, 0, 0, 9, 0, 4, 7, 1, 1, 4, 5, 6, 0, 6, 9, 9, 4, 9, 3, 9, 5, 2, 0, 0, 2, 4, 0, 5, 9, 4, 2, 2, 0, 8, 3, 3, 1, 7, 3, 5, 3, 6, 6, 8, 2, 8, 9, 0, 0, 5, 7, 2, 0, 4};
    reverse(randNum1.begin(), randNum1.end());
    reverse(randNum2.begin(), randNum2.end());
    vector<int> mulResult {6, 3, 5, 9, 6, 5, 1, 1, 9, 8, 4, 0, 6, 5, 9, 1, 4, 3, 2, 7, 1, 1, 2, 7, 8, 1, 8, 5, 0, 2, 8, 8, 2, 3, 1, 7, 5, 9, 0, 7, 0, 9, 5, 2, 7, 2, 9, 2, 8, 7, 0, 0, 3, 1, 7, 8, 9, 9, 0, 4, 0, 5, 4, 6, 9, 5, 0, 4, 9, 0, 2, 1, 7, 6, 3, 3, 9, 8, 2, 7, 4, 3, 7, 3, 4, 6, 8, 3, 9, 3, 7, 9, 1, 1, 7, 8, 2, 4, 0, 4, 1, 5, 0, 2, 5, 0, 7, 1, 5, 6};
    vector<int> res = karatsuba(randNum1, randNum2);
    reverse(res.begin(), res.end());
    printAll(res);
    return 0;
}

void normalize(vector<int>& num){
    num.push_back(0);
    for(auto i = 0; i + 1 < num.size(); ++i){
        if(num[i] < 0){
            int borrow = (abs(num[i]) + 9) / 10;
            num[i + 1] -= borrow;
            num[i] += borrow * 10;
        }else{
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while(num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b){
    vector<int> c(a.size() + b.size() + 1, 0);
    for(auto i = 0; i < a.size(); ++i){
        for(auto j = 0; j < b.size(); ++j){
            c[i + j] += a[i] * b[j];
        }
    }
    normalize(c);
    return c;
}

void addTo(vector<int>& a, const vector<int>& b, int k){ // a+= b * (10 ^ k)
    int orgSize = a.size();
    if(orgSize < b.size() + k) a.resize(b.size() + k, 0);
    a.push_back(0);

    int bSize = b.size();

    for(auto i = 0; i < bSize; ++i){
        a[i + k] += b[i];
    }
    normalize(a);
}


void subFrom(vector<int>& a, const vector<int>& b){
    int bSize = b.size();
    for(auto i = 0; i < bSize; ++i){
        a[i] -= b[i];
    }
    normalize(a);
}


vector<int> karatsuba(const vector<int>& a, const vector<int>& b){
    int an = a.size(), bn = b.size();
    if(an < bn) return karatsuba(b, a);
    if(an == 0 || bn == 0) return vector<int>();
    if(an <= 50) return multiply(a, b);
    int half = an >> 1;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);
    addTo(a0, a1, 0); addTo(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0); subFrom(z1, z2);
    vector<int> ret;
    addTo(ret, z0, 0); addTo(ret, z1, half); addTo(ret, z2, half + half);
    return ret;
}

void printAll(const vector<int>& a){
    for(auto& e : a) cout << e << ' ';
    cout << endl;
}