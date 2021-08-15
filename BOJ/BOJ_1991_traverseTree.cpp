#include <iostream>
using namespace std;

typedef struct{
    int left;
    int right;
}Node;

Node node[51];

void preorder(int x){
    if(x == -1) return;
    cout << (char)(x + 'A');
    preorder(node[x].left);
    preorder(node[x].right);
}
void inorder(int x){
    if(x == -1) return;
    inorder(node[x].left);
    cout << (char)(x + 'A');
    inorder(node[x].right);
}
void postorder(int x){
    if(x == -1) return;
    postorder(node[x].left);
    postorder(node[x].right);
    cout << (char)(x + 'A');
}

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        char a, b, c;
        cin >> a >> b >> c;
        a -= 'A';
        if(b == '.'){
            node[a].left = -1;
        }else{
            node[a].left = b - 'A';
        }
        if(c == '.'){
            node[a].right = -1;
        }else{
            node[a].right = c - 'A';
        }
    }
    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);
    cout << endl;
    return 0;
}