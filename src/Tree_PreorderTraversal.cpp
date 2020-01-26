#include "BST.h"
#include <iostream>
#include <stack>

using namespace std;

void PrintPreorderRec(Node* root);
void PrintPreorderIter(Node* root);
void PrintPreorderIterSimpler(Node* root);

int main(){
    //Node* t = new Node(5, new Node(3, new Node(1), new Node(4)), new Node(2, new Node(7), new Node(9)));
    Node* t = new Node(5);
    t->Insert(1);
    t->Insert(4);
    t->Insert(2);
    t->Insert(7);
    t->Insert(9);
    PrintPreorderRec(t);
    cout << endl;
    PrintPreorderIter(t);
    cout << endl;
    PrintPreorderIterSimpler(t);
    delete t;
    return 0;
}

void PrintPreorderRec(Node* root){
    if(root != nullptr){
        cout << root->getKey() << endl;
        PrintPreorderRec(root->getLeft());
        PrintPreorderRec(root->getRight());
    }
}

void PrintPreorderIter(Node* root){
    stack<Node*> st;
    st.push(root);
    Node* t;

    while(!st.empty()){
        t = st.top();
        st.pop();
        while(t != nullptr){
            cout << t->getKey() << endl;
            st.push(t->getRight());
            t = t->getLeft();
        }
    }
}

void PrintPreorderIterSimpler(Node* root){
    stack<Node*> st;
    st.push(root);
    Node* t;

    while(!st.empty()){
        t = st.top();
        st.pop();
        if(t != nullptr){
            cout << t->getKey() << endl;
            st.push(t->getRight());
            st.push(t->getLeft());
        }
    }
}
