#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    vector<int> HashVector = vector<int>(128,0);

    for(char c : a){
        HashVector.at(int(c))++;
    }

    for(char c : b){
        HashVector.at(int(c))--;
    }

    int result = 0;

    for(int h : HashVector){
        result += abs(h);
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
