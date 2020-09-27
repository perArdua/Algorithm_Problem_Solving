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
int calWidth = 1, calLevel = 1; // 기본 값을 각각 1로 지정한 이유는 최소로 가질 수 있는 너비와 레벨이 모두 1 이기 때문이다. (root일 경우)

void inorder(int x, int level){ // 순회를 통하여 각 노드들의 열 번호와, 행 번호를 표시한다
    if(x == -1) return;

    inorder(node[x].left, level + 1);
    node[x].col = ++c;
    node[x].row = level;
    inorder(node[x].right, level + 1);
}

void postorder(int x, bool* v){ // 순회를 통하여 각 노드들을 방문한다
    if(x == -1) return;
    
    postorder(node[x].left, v);
    postorder(node[x].right, v);
    v[x] = true;
}

int findRoot(){ // 루트 노드의 번호를 반환한다
    bool visited[10001];
    for(int i = 1; i <= n; ++i){ // i번 노드를 루트라고 가정하고 방문을 시도한다
        bool isFind = true;
        memset(visited, 0, sizeof(visited));
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

void calc(){ // 레벨이 같은 노드들에 대해서만 너비를 계산한다.
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