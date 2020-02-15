#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <iostream>

class Node{
private:
    int Key;
    Node* Left;
    Node* Right;
public:
    Node();
    Node(int a);
    Node(const Node& Copy);
    ~Node();
    Node& operator=(const Node& Object);

    bool Exist(int a);
    void Insert(int a);
    Node* getLeft();
    Node* getRight();
    int getKey();
    void print();
};
Node::Node(){
    Key = -1;
    Right = nullptr;
    Left = nullptr;
}
Node::Node(int a){
    Key = a;
    Right = nullptr;
    Left = nullptr;
}
void Node::Insert(int a){
    if(Key < 0){
        Key = a;
    }
    else if(a > Key){
        if(Right == nullptr){
            Right = new Node(a);
        }
        else{
            Right->Insert(a);
        }
    }
    else{
        if(Left == nullptr){
            Left = new Node(a);
        }
        else{
            Left->Insert(a);
        }
    }
}
void Node::print(){
    std::cout << Key << std::endl;
    if(Left != nullptr){
            Left->print();
    }
    if(Right != nullptr){
            Right->print();
    }
}

int Node::getKey(){
    //std::cout << "In getKey" << std::endl;
    return Key;
}

Node* Node::getLeft(){
    return Left;
}

Node* Node::getRight(){
    return Right;
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

bool Node::Exist(int a){
    if(Key == a){
        return true;
    }
    if(Key < a){
        if(Right == nullptr){
            return false;
        }
        return Right->Exist(a);
    }
    if(Left == nullptr){
            return false;
        }
    return Left->Exist(a);
}

#endif // BST_H_INCLUDED
