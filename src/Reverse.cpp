#include <iostream>
#include <stack>

using namespace std;

void Reverse_word(string s);

int main(){

Reverse_word("Hello world.");

return 0;
}

void Reverse_word(string s){
    string buffer = "";
    stack<string> words;

    for(char c : s){
        if(c == ' '){
            words.push(buffer);
            buffer = "";
        }
        else{
            buffer += c;
        }
    }

    words.push(buffer);

    while(!words.empty()){
        cout << words.top() << " ";
        words.pop();
    }
    cout << endl;
}
