#include <bits/stdc++.h>

using namespace std;

int commonChild(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();

    int C[n1+1][n2+1];

    for(int i = 0; i < n1; i++){
        C[i][0] = 0;
        C[0][i] = 0;
        C[n1][i] = 0;
        C[i][n1] = 0;
    }
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n1; j++){
            if(s1.at(i) == s2.at(j)){
                C[i+1][j+1] = 1 + C[i][j];
            }
            else{
                int a = C[i][j+1];
                int b = C[i+1][j];
                C[i+1][j+1] = a > b ? a : b;
            }
        }
    }

    for(int i = 0; i < n1+1; i++){
        for(int j = 0; j < n2+1; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return C[n1][n2];
}

int main()
{
    string s1;
    string s2;

    s1 = "SHINCHAN";
    s2 = "NOHARAAA";

    cout << "should be 3, is : " << commonChild(s1, s2) << endl;

    s1 = "HARRY";
    s2 = "SALLY";

    cout << "should be 2, is : " << commonChild(s1, s2) << endl;

    s1 = "AA";
    s2 = "BB";

    cout << "should be 0, is : " << commonChild(s1, s2) << endl;

    s1 = "ABCDEF";
    s2 = "FBDAMN";

    cout << "should be 2, is : " << commonChild(s1, s2) << endl;

    return 0;
}
