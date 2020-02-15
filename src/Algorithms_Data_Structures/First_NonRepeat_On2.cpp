#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

char Find_FirstNon(string s);

int main(){

cout << Find_FirstNon("total") << endl;
cout << Find_FirstNon("teeter") << endl;

return 0;
}

char Find_FirstNon(string s){

vector<pair<char, int> > Hash_Vector;

for(char c : s){
    vector<pair<char, int> >::iterator p = std::find(Hash_Vector.begin(), Hash_Vector.end(), make_pair(c,2));
    if( p == Hash_Vector.end()){
        vector<pair<char, int> >::iterator p2 = find(Hash_Vector.begin(), Hash_Vector.end(), make_pair(c,1));
        if(p2 != Hash_Vector.end()){
            p2->second = 2;
        }
        else{
            Hash_Vector.push_back(make_pair(c,1));
        }
    }
}

for(pair<char,int> p : Hash_Vector){
    if( p.second == 1){
        return p.first;
    }
}
return -1;
}
