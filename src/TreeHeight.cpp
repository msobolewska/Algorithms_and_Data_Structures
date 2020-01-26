#include "Tree.h"
#include <iostream>

using namespace std;

Node* findNode(Node* root, int value);
Node* findNodeRec(Node* root, int value);
int findHeight(Node* root);
int SumSync(Node* root, int sum);

int main(){
    //Node* t = new Node(5, new Node(3, new Node(1), new Node(4)), new Node(2, new Node(7), new Node(9)));
    Node* t = new Node(5, new Node(3), new Node(2));
    //t->print2();
    //std::cout << SumSync(t,0) << std::endl;
    std::cout << findHeight(t) << std::endl;
    delete t;
    return 0;
}

Node* findNode(Node* root, int value){
    while(root != nullptr){
        if(root->getKey() == value){
            break;
        }
        if(root->getKey() < value){
            root = root->getRight();
        }
        else{
            root = root->getLeft();
        }
    }
    return root;
}
Node* findNodeRec(Node* root, int value){
    if(root == nullptr){
        return nullptr;
    }
    if(root->getKey() == value){
        return root;
    }
    if(root->getKey() < value){
        return findNodeRec(root->getRight(), value);
    }
    else
        return findNodeRec(root->getLeft(), value);

    return nullptr;
}
int findHeight(Node* root){
    if(root == nullptr){
        return 0;
    }
    return 1 + std::max(findHeight(root->getLeft()),findHeight(root->getRight()));
}
int SumSync(Node* root, int sum){
    if(root == nullptr){
        return 0;
    }
    sum *= 10;
    sum += root->getKey();
    if(root->getLeft() == nullptr){
        if(root->getRight() == nullptr){
            return sum;
        }
        else{
            return sum + SumSync(root->getRight(),sum);
        }
    }
    else if(root->getRight() == nullptr){
            return sum + SumSync(root->getLeft(),sum);
        }
    return SumSync(root->getLeft(),sum)+SumSync(root->getRight(),sum);
    return 0;
}
