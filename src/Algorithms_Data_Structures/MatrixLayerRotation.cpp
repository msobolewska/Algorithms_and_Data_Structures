#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int r) {
    int m = matrix.size();
    int n = (matrix.at(0)).size();

    for(int i = 0; i < m/2 && i < n/2; i++){
    // i defines layer

        vector<int> temp;
        int k, j;
        k = j = i;

        // 1 create a vector out of one layer, direction: clockwise

        while(k <= n - 2 - i){
            temp.push_back(matrix[j][k]);
            k++;
        }

        while(j <= m - 2 - i){
            temp.push_back(matrix[j][k]);
            j++;
        }

        while(k >= i+1){
            temp.push_back(matrix[j][k]);
            k--;
        }

        while(j >= i+1){
            temp.push_back(matrix[j][k]);
            j--;
        }
        // here k, j = i

        // 2 perform shift
        int start = r % temp.size();

        // 3 put temp back into matrix starting from position defined by start variable

        // at start: j, k = i
        int tempToken = start;
        while(k <= n - 2 - i){
            matrix[j][k] = temp[tempToken];
            k++;
            tempToken = (tempToken + 1 ) % temp.size();
        }

        while(j <= m - 2 - i){
            matrix[j][k] = temp[tempToken];
            j++;
            tempToken = (tempToken + 1 ) % temp.size();
        }

        while(k >= i+1){
            matrix[j][k] = temp[tempToken];
            k--;
            tempToken = (tempToken + 1 ) % temp.size();
        }

        while(j >= i+1){
            matrix[j][k] = temp[tempToken];
            j--;
            tempToken = (tempToken + 1 ) % temp.size();
        }
        temp.clear();
    }
    // print the result

    for(vector<int> row : matrix){
        for(int i : row){
            cout << i << " ";
        }
        cout << endl;
    }

}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
