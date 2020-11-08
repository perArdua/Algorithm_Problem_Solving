#include <iostream>
#include <string>
#include <stack>
#include <vector>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int main(){
    FAST;
    int n;
    string exp;
    vector<double> op(n);
    stack<double> alpha;
    cin >> n;
    cin >> exp;
    rep(i, 0, n){
        cin >> op[i];
    }
    double res = 0;
    cout.setf(ios::fixed);
    cout.precision(2);
    rep(i, 0, exp.size()){
        if('A' <= exp[i] && exp[i] <= 'Z'){
            alpha.push(op[exp[i] - 'A']);
        }else{
            double right = alpha.top(); alpha.pop();
            double left = alpha.top(); alpha.pop();
            switch (exp[i]){
            case '+':
                alpha.push(left + right);
                break;
            case '-':
                alpha.push(left - right);
                break;
            case '*':
                alpha.push(left * right);
                break;
            case '/':
                alpha.push(left / right);
                break;
            }
        }
    }
    cout << alpha.top();
    return 0;
}
// ?