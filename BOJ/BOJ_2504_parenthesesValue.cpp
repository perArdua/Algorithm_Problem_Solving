#include <iostream>
#include <string>
#include <stack>
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define rep(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int cal(const string& s){
    int ret = 0;
    stack<string> st;
    const string par = "([])";
/* stack top에 숫자 -> 덧셈, 숫자x -> 곱셈 진행 */
    string tmp_string;
    rep(i, 0, s.size()){
        tmp_string = s.at(i);
        if(tmp_string == "(" || tmp_string == "["){
            st.push(tmp_string);
        }else{
            int tmpSum = 0;
            while(!st.empty() && st.top() != "(" && st.top() != "["){
                tmpSum += stoi(st.top()); st.pop();
            }
            if(st.empty()) return 0;
            if(st.top() != "[" && tmp_string == "]") return 0;
            else if(st.top() != "(" && tmp_string == ")") return 0;

            if(tmp_string == ")"){
                if(tmpSum != 0){
                    st.pop();
                    st.push(to_string(tmpSum * 2));
                }else{
                    st.pop();
                    st.push(to_string(2));
                }
            }else if(tmp_string == "]"){
                if(tmpSum != 0){
                    st.pop();
                    st.push(to_string(tmpSum * 3));
                }else{
                    st.pop();
                    st.push(to_string(3));
                }
            }
        }
    }
    while(!st.empty()){
        if(par.find(st.top()) != string::npos) return 0;
        ret += stoi(st.top()); st.pop();
    }
    return ret;
}

int main(){
    FAST;
    string src;
    cin >> src;
    cout << cal(src) << endl;
    return 0;
}
// ?