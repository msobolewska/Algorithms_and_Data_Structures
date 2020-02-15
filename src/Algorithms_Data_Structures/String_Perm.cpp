#include <iostream>
#include <vector>

using namespace std;

class Permutations{
private:
    string inp;
    string sol;
    string com;
    int token;
    vector<bool> used;

public:
    Permutations(string in);
    Permutations(const Permutations&);
    ~Permutations(){};
    Permutations operator=(const Permutations&);

    //API
    void PrintAllPer();
    void PrintAllComb();
};

Permutations::Permutations(string in){
    inp = in;
    int n = inp.size();
    used = vector<bool>(n, false);
    sol = "";
    com = "";
    token = 0;
}

Permutations::Permutations(const Permutations& p){
    inp = p.inp;
    int n = inp.size();
    used = vector<bool>(n);
    sol = p.sol;
    com = p.com;
    token = p.token;
    for(int i = 0; i < n; i++){
        used.at(i) = p.used.at(i);
    }
}

Permutations Permutations::operator=(const Permutations& p){
    inp = p.inp;
    int n = inp.size();
    used = vector<bool>(n);
    sol = p.sol;
    com = p.com;
    token = p.token;
    for(int i = 0; i < n; i++){
        used.at(i) = p.used.at(i);
    }
    return *this;
}

void Permutations::PrintAllPer(){
    //base case
    if(sol.size() == used.size()){
        cout << sol << endl;
        return;
    }

    //recursive case
    for(int i = 0; i < used.size(); i++){
        if(used.at(i) == false){
            used.at(i) = true;
            sol += inp.at(i);
            PrintAllPer();
            used.at(i) = false;
            sol.pop_back();
        }
    }
}

void Permutations::PrintAllComb(){
    //base case
    if(com.size() != 0){
        cout << com << endl;
    }

    //recursive case
    for(int i = token; i < inp.size(); i++){
        com += inp.at(i);
        token = i+1;
        PrintAllComb();
        token = i+1;
        com.pop_back();
    }
}

int main(){

    Permutations a = Permutations("abc");
    a.PrintAllComb();

    return 0;
}
