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
vector<int> multiply(const vector<int>& a, const vector<int>& b); // 자릿수 작은 숫자의 곱
void addTo(vector<int>& a, const vector<int>& b, int k); // a += b * (10 ^ k)
void subFrom(vector<int>& a, const vector<int>& b); // a -= b (a >= b)
vector<int> karatsuba(const vector<int>& a, const vector<int>& b);
int hugs(const string& a, const string& b);

int main(){
    FAST;
    int t;
    cin >> t;
    rep(tc, 0, t){
        string a, b;
        cin >> a >> b;
        cout << hugs(a, b) << endl;
    }
    return 0;
}


vector<int> multiply(const vector<int>& a, const vector<int>& b){
    vector<int> c(a.size() + b.size() + 1, 0);
    for(auto i = 0; i < a.size(); ++i){
        for(auto j = 0; j < b.size(); ++j){
            c[i + j] += a[i] * b[j];
        }
    }
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
}


void subFrom(vector<int>& a, const vector<int>& b){
    int bSize = b.size();
    for(auto i = 0; i < bSize; ++i){
        a[i] -= b[i];
    }
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


int hugs(const string& a, const string& b){
    int aSize = a.size(), bSize = b.size();
    vector<int> member(aSize), fan(bSize);
    rep(i, 0, aSize) member[i] = (a[i] == 'M');
    rep(i, 0, bSize) fan[bSize - i - 1] = (b[i] == 'M');
    vector<int> res = karatsuba(member, fan);
    int ret = 0;
    rep(i, aSize - 1, bSize) if(!res[i]) ++ret;
    return ret;
}
