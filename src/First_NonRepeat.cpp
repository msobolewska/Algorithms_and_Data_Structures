#include<iostream>
#include<unordered_map>

using namespace std;

char Find_FirstNon(string s);

int main(){

cout << Find_FirstNon("total") << endl;
cout << Find_FirstNon("teeter") << endl;

return 0;
}

char Find_FirstNon(string s){

unordered_map<char,int> Hash_Map;

for(char c : s){
    Hash_Map[c]++;
}

for(char c : s){
    if( Hash_Map[c] == 1){
        return c;
    }
}
return -1;
}
