#include <iostream>
#define endl "\n"
using namespace std;

struct Node{
    int left;
    int right;
    int col;
    int depth;
};

Node node[10001];
const int INF = 987654321;
int n;
int c = 1;
int calWidth = -1, calLevel = INF;

void inorder(int x){
    if(x == -1) return;

    inorder(node[x].left);
    node[x].col = c;
    ++c;
    inorder(node[x].right);
}

void preorder(int x, int level){
    if(x == -1) return;
    
    node[x].depth = level;
    preorder(node[x].left, level + 1);
    preorder(node[x].right, level + 1);
}

void calc(){
    for(int curNode = 1; curNode <= n; ++curNode){
        for(int nextNode = 1; nextNode <=n; ++nextNode){
            if(curNode == nextNode) continue;
            if(node[curNode].depth != node[nextNode].depth) continue;
           
            int res = abs(node[curNode].col - node[nextNode].col) + 1;
            if(res > calWidth){
                calWidth = res;
                calLevel = node[curNode].depth;
            }else if(res == calWidth){
                if(node[curNode].depth < calLevel){
                    calLevel = node[curNode].depth;
                }
            }

        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int parent, leftChild, rightChild;
        cin >> parent >> leftChild >> rightChild;
        node[parent].left = leftChild;
        node[parent].right = rightChild;
    }
    inorder(1);
    preorder(1, 1);
    calc();
    cout << calLevel << " " << calWidth;    
    return 0;
}
// ?