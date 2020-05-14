#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
    int n = arr.size();
    if(n == 1){
        return arr.at(0);
    }

    // general solution
    vector<int> sol;

    sol.push_back(arr.at(0));
    int max_so_far;

    if(arr.at(0) > arr.at(1)){
        sol.push_back(arr.at(0));
        max_so_far = sol.at(0);
    }
    else{
        sol.push_back(arr.at(1));
        max_so_far = sol.at(1);
    }

    int a, b;

    for(int i = 2; i < n; i++){
        a = arr.at(i)+sol.at(i-2);
        b = arr.at(i);
        if(max_so_far > b && max_so_far > a){
            sol.push_back(max_so_far);
        }
        else if(a > b){
            sol.push_back(a);
            max_so_far = a;
        }
        else{
            sol.push_back(b);
            max_so_far = b;
        }
    }


    return sol.back();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = maxSubsetSum(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
