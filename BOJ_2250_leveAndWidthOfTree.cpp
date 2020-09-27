#include <iostream>
#include <cstring>
#include <cstdlib>
#define endl "\n"
using namespace std;

typedef struct{
    int left;
    int right;
    int col;
    int row;
}Node;

Node node[10001];
int n;
int c = 0;
int calWidth = 1, calLevel = 1;

void inorder(int x, int level){
    if(x == -1) return;

    inorder(node[x].left, level + 1);
    node[x].col = ++c;
    node[x].row = level;
    inorder(node[x].right, level + 1);
}

void postorder(int x, bool* v){
    if(x == -1) return;
    
    postorder(node[x].left, v);
    postorder(node[x].right, v);
    v[x] = true;
}

int findRoot(){
    bool visited[10001];
    bool isFind = true;
    for(int i = 1; i <= n; ++i){
        memset(visited, false, sizeof(visited));
        postorder(i, visited);
        for(int j = 1; j <= n; ++j){
            if(!visited[j]){
                isFind = false;
                break;
            }
        }
        if(isFind) return i;
    }
    return -1;
}

void calc(){
    for(int curNode = 1; curNode <= n; ++curNode){
        for(int nextNode = 1; nextNode <=n; ++nextNode){
            if(curNode == nextNode) continue;
            if(node[curNode].row != node[nextNode].row) continue;
           
            int res = abs(node[curNode].col - node[nextNode].col) + 1;
            if(res > calWidth){
                calWidth = res;
                calLevel = node[curNode].row;
            }else if(res == calWidth){
                if(node[curNode].row < calLevel){
                    calLevel = node[curNode].row;
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
    inorder(findRoot(), 1);
    calc();
    cout << calLevel << " " << calWidth;
    return 0;
}