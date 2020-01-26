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

Node* findNode(Node* root, int value);
Node* findNodeRec(Node* root, int value);
int findHeight(Node* root);
int SumSync(Node* root, int sum);

int main(){
    //Node* t = new Node(5, new Node(3, new Node(1), new Node(4)), new Node(2, new Node(7), new Node(9)));
    Node* t = new Node(5, new Node(3), new Node(2));
    //t->print2();
    std::cout << SumSync(t,0) << std::endl;
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
