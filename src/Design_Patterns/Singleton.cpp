#include <bits/stdc++.h>

using namespace std;

class MySingleton
{
    // private constructor can't be accessed outside the class
private:
    static MySingleton *instance;
    MySingleton() {};
    ~MySingleton(){};

    // Factory method to provide the users with instances
public:
    int x = 10;
    static MySingleton* getInstance()
    {
        if (instance == nullptr)
             instance = new MySingleton();

        return instance;
    }
};

MySingleton* MySingleton::instance = nullptr;

int main(){

    MySingleton *a;
    a = a->getInstance();
    MySingleton *b = b->getInstance();
    a->x = a->x + 10;
    cout<< "Value of a.x = " << a->x << endl;
    cout<< "Value of b.x = " << b->x << endl;

return 0;
}
