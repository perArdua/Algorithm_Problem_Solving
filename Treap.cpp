#ifndef __Treap__
#define __Treap__

#include <iostream>
#include <utility>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef int KeyType;

struct Node{
    KeyType key;
    int priority, size;
    Node *left, *right;
    Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(nullptr), right(nullptr){}
    void setLeft(Node* newLeft){ left = newLeft; calcSize();}
    void setRight(Node* newRight){ right = newRight; calcSize();}
    void calcSize(){
        size = 1;
        if(left) size += left->size;
        if(right) size += right->size;
    }
};

typedef pair<Node*, Node* > NodePair;
NodePair split(Node* root, KeyType key){
    if(root == nullptr) return NodePair(nullptr, nullptr);
    
    if(root -> key < key){
        NodePair rs = split(root -> right, key);
        root -> setRight(rs -> first);
        return Node(root, rs -> setRight);
    }
    NodePair ls = split(root -> left, key);
    root -> setLeft(ls.second);
    return NodePair(ls.first, root);
}

Node* insert(Node* root, Node* node){
    if(root == nullptr) return node;
    if(root -> priority < node -> priority){
        NodePair splitted = split(root, node -> key);
        node -> setLeft(splitted.first);
        node -> setRight(splitted.second);
        return node;
    }else if(node -> key < root -> key){
        root -> setLeft(insert(root -> left, node));
    }else{
        root -> setRight(insert(root -> right, node));
    }
    return root;
}

Node* merge(Node* a, Node* b){
    if(a == nullptr) return b;
    if(b == nullptr) return a;
    if(a -> priority < b -> priority){
        b -> setLeft(merge(a, b -> left));
        return b;
    }
    a -> setLeft(merge(a -> right, b));
    return a;
}

Node* erase(Node* root, KeyType key){
    if(root == nullptr) return root;
    if(root -> key < key){
        Node* ret = merge(root -> left, root -> right);
        delete root;
        return ret;
    }
    if(key < root -> key)
        root -> setLeft(erase(root -> left, key));
    else
        root -> setRight(erase(root -> right, key));
    return root;
}

#endif