#include <bits/stdc++.h>

using namespace std;

bool abbreviation_help(string a, string b);

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    int n = a.size()+1;
    int m = b.size()+1;
    bool** dp = new bool*[n];

    for(int i = 0; i < n; i++){
        dp[i] = new bool[m];
    }

    dp[0][0] = true;

    for(int i = 1; i < b.size()+1; i++){
        dp[0][i] = false;
    }

    bool upper_happ = false;
    for(int j = 1; j < a.size()+1; j++){
        if(int(a.at(j-1)) <= 90 || upper_happ){
            upper_happ = true;
            dp[j][0] = false;
        }
        else{
            dp[j][0] = true;
        }
    }
    for(int row = 1; row < a.size()+1; row++){
        for(int col = 1; col < b.size()+1; col++){
            if(a.at(row-1) == b.at(col-1)){
                dp[row][col] = dp[row-1][col-1];
            }
            else if(int(a.at(row-1)) >= 97 ){
                if(int(a.at(row-1)-32) == int(b.at(col-1))){
                    dp[row][col] = dp[row-1][col-1] || dp[row-1][col];
                }
                else{
                    dp[row][col] = dp[row-1][col];
                }
            }
            else{
                dp[row][col] = false;
            }
        }
    }

    for(int row = 0; row < a.size()+1; row++){
        for(int col = 0; col < b.size()+1; col++){
            cout << dp[row][col] << " ";
        }
        cout << endl;
    }

    cout << dp[a.size()][b.size()] << endl;
    return dp[a.size()][b.size()] ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
