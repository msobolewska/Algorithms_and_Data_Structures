#include <iostream>

typedef struct LinkedListInt{
    int element;
    struct LinkedListInt *next;
}LinkedListInt;

//when used needs to have ListElement<int>
template<class T>
class ListElement{
private:
    T data;
    ListElement *next;
public:
    ListElement(const T &value): next(NULL), data (value){}
    ~ListElement(){}

    //API
    ListElement *getNext() const { return next; }
    const T& value() const { return data; }
    void setNext ( ListElement *elem ) { next = elem; }
    void setValue( const T &value) { data = value; }
};

int main(){
return 0;
}
