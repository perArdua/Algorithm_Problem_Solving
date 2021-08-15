#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

using ull = unsigned long long;

const ull MOD = 1000000007LL;
ull input;

class fiboMatrix{
    public:
    vector<vector<ull> > matrix;

    fiboMatrix() : matrix(2, vector<ull>(2, 0)) {}

    fiboMatrix baseCase(){
        fiboMatrix ret;
        ret.matrix[0][0] = 1;
        ret.matrix[0][1] = 1;
        ret.matrix[1][0] = 1;
        return ret;
    }

    fiboMatrix rightBase(){
        fiboMatrix ret;
        ret.matrix[0][0] = 1;
        return ret;
    }

    fiboMatrix identity(){
        fiboMatrix ret;
        for(int i = 0; i < 2; ++i){
            ret.matrix[i][i] = 1;
        }
        return ret;
    }

    fiboMatrix operator* (const fiboMatrix& A){
        fiboMatrix ret;
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 2; ++j){
                for(int k = 0; k < 2; ++k){
                    ret.matrix[i][j] += matrix[i][k] * A.matrix[k][j];
                }
                ret.matrix[i][j] %= MOD;
            }
        }
        return ret;
    }
    fiboMatrix pow(const fiboMatrix& A, ull exp){
        if(exp == 0) return identity();
        if(exp % 2 > 0) return pow(A, exp - 1) * A;
        fiboMatrix half = pow(A, exp / 2);
        return half * half;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> input;
    fiboMatrix res;
    res = res.pow(res.baseCase(), input);
    res = res * res.rightBase();
    cout << res.matrix[1][0] + res.matrix[1][1];
    return 0;
}
// ?