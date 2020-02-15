#include<iostream>

using namespace std;

void Remove_Specific(string s, string r);

int main(){
string s = "Battle of the Vowels: Hawaii vs. Grozny";
cout << s << endl;
Remove_Specific(s, "aeiou");
cout << s << endl;

return 0;
}

void Remove_Specific(string s, string r){
    bool* HashArray = new bool[128];

    cout << s.size() << endl;

    for(char c : r){
        HashArray[int(c)] = true;
    }

    int i = 0;
    int ins = 0;

    while(i < s.size()){
        char c = s.at(i++);
        if(!HashArray[int(c)]){
            s.at(ins++) = c;
        }
    }

    s.erase(ins, s.size()-ins);

    cout << s << endl;
    cout << s.size() << endl;
    delete[] HashArray;
}
