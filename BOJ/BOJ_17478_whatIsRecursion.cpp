#include <iostream>
#include <string>
#define endl "\n"

using namespace std;

int n;
string tmp1 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
string tmp2 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
string tmp3 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
string s1 = "\"재귀함수가 뭔가요?\"\n";
string s3 = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
string s4 = "라고 답변하였지.\n";


void recursion(int s, string next){
    if(s == n){
        cout << next + s1;
        cout << next + s3;
        cout << next + s4;
        return;
    }

    cout << next + s1;
    cout << next + tmp1;
    cout << next + tmp2;
    cout << next + tmp3;
    recursion(s + 1, "____" + next);
    cout << next + s4;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
    cin >> n;
    recursion(0, "");
    return 0;
}