#include "bits/stdc++.h"

using namespace std;

class Window{

private:
    bool visible;
    bool modal;
    bool dialog;

public:
    Window(bool visible, bool modal, bool dialog){
        this->visible = visible;
        this->modal = modal;
        this->dialog = dialog;
    }
    ~Window(){};
};

class WindowBuilder{

private:
    bool visible;
    bool modal;
    bool dialog;

public:
    WindowBuilder(){};
    WindowBuilder setDialog(bool flag){
        dialog = flag;
        return *this;
    }

    WindowBuilder setModal(bool flag){
        modal = flag;
        return *this;
    }

    WindowBuilder setVisible(bool flag){
        visible = flag;
        return *this;
    }

    Window* build(){
        return new Window(visible, modal, dialog);
    }
};

int main(){

    Window* w1 = new Window(false, true, true);
    Window* w2 = (new WindowBuilder())->setVisible(false).setDialog(true).setModal(true).build();

return 0;
}
