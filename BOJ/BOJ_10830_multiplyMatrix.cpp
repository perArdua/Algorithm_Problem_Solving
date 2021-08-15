#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

typedef unsigned long long ull;
const ull MOD = 1000;
int n;
ull b;

class SquareMatrix{
    public:
    vector<vector<ull> > matrix;
    int size;
    // friend istream &operator>> (istream&, SquareMatrix&);
    // friend ostream &operator<< (ostream&, const SquareMatrix&);

    public:
        SquareMatrix(int a) : size{a} {
            matrix = vector<vector<ull> >(a, vector<ull>(a, 0));
        }

        SquareMatrix identity(int n){
            SquareMatrix ret(n);
            for(auto i = 0; i < n; ++i){
                ret.matrix[i][i] = 1;
            }
            return ret;
        }

        SquareMatrix operator*(const SquareMatrix& A){
            auto ret = SquareMatrix(A.size);
            for(auto i = 0; i < ret.size; ++i){
                for(auto j = 0; j < ret.size; ++j){
                    for(auto k = 0; k < ret.size; ++k){
                        ret.matrix[i][j] += matrix[i][k] * A.matrix[k][j];
                    }
                    ret.matrix[i][j] %= MOD;
                }
            }
            return ret;
        }

        SquareMatrix pow(const SquareMatrix& A, ull exp){
            if(exp == 0) return identity(A.size);
            if(exp % 2 > 0) return pow(A, exp - 1) * A;
            SquareMatrix half = pow(A, exp / 2);
            return half * half;
        }
};

// istream& operator>>(istream& in, SquareMatrix& A){
//     for(auto i = 0; i < n; ++i){
//         for(auto j = 0; j < n; ++j){
//             in >> A.matrix[i][j];
//         }
//     }
// }

// ostream& operator<<(ostream& out , const SquareMatrix& A){
//     for(auto i = 0; i < A.size; ++i){
//         for(auto j = 0; j < A.size; ++j){
//             out << A.matrix[i][j] << " ";
//         }
//         out << endl;
//     }
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> b;
    SquareMatrix mat(n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> mat.matrix[i][j];
        }
    }
    auto ret = mat.pow(mat, b);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << ret.matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}