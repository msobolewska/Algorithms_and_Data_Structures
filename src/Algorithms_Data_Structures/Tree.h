#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>

class Node{
private:
    int Key;
    Node* Left;
    Node* Right;
public:
    Node(int a);
    Node(int a, Node* left, Node* right);
    Node(const Node& Copy);
    ~Node();
    Node& operator=(const Node& Object);

    Node* getLeft();
    Node* getRight();
    int getKey();
    void print();
    void print2();
};
void Node::print(){
    std::cout << Key << std::endl;
    if(Left != nullptr){
            Left->print();
    }
    if(Right != nullptr){
            Right->print();
    }
}
void Node::print2(){
    //print for function
    if(this != nullptr){
            Left->print2();
            std::cout << Key << std::endl;
            Right->print2();
    }
    //std::cout << Key << std::endl;
}
int Node::getKey(){
    //std::cout << "In getKey" << std::endl;
    return Key;
}
Node::Node(int a, Node* left, Node* right){
    Key = a;
    if(left != nullptr){
        Left = new Node(*left);
    }
    else{
        Left = nullptr;
    }
    if(right != nullptr){
        Right = new Node(*right);
    }
    else{
        Right = nullptr;
    }
}

Node* Node::getLeft(){
    return Left;
}

Node* Node::getRight(){
    return Right;
}

Node::Node(int a){
    Key = a;
    Left = nullptr;
    Right = nullptr;
}

Node& Node::operator=(const Node& Object){
    delete Left;
    delete Right;

    Left = new Node(*Object.Left);
    Right = new Node(*Object.Right);

    Key = Object.Key;

    return *this;
}

Node::Node(const Node& Copy){
    if(Copy.Left != nullptr){
        Left = new Node(*Copy.Left);
    }
    else {
        Left = nullptr;
    }
    if(Copy.Right != nullptr){
        Right = new Node(*Copy.Right);
    }
    else{
        Right= nullptr;
    }
    Key = Copy.Key;
}

Node::~Node(){
    delete Left;
    delete Right;
}


#endif // TREE_H_INCLUDED
