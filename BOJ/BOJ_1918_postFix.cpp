#include <iostream>
#include <stack>
#include <string>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int main(){
    FAST;
    string str;
    getline(cin, str);
    stack<char> _s;
    rep(i, 0, str.size()){
            /* operand */
        if('A' <= str[i] && str[i] <= 'Z'){
            cout << str[i];
        }else{
            /* _s */
            switch (str[i]){
            case '(' :
                _s.push(str[i]);
                break;
            case '*':
            case '/':
                while(!_s.empty() && (_s.top() == '*' || _s.top() == '/')){
                    cout << _s.top();
                    _s.pop();
                }
                _s.push(str[i]);
                break;
            case '+':
            case '-':
                while(!_s.empty() && (_s.top() != '(')){
                    cout << _s.top();
                    _s.pop();
                }
                _s.push(str[i]);
                break;
            case ')':
                while(_s.top() != '('){
                    cout << _s.top();
                    _s.pop();
                }
                _s.pop();
                break;
            } // end switch
        }
    }
    while(!_s.empty()){
        cout << _s.top();
        _s.pop();
    }
    return 0;
}
// ?