#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {
    int n = cost.size();
    // create copy
    vector<int> sorted_copy;
    for(int i : cost){
        sorted_copy.push_back(i);
    }
    sort(sorted_copy.begin(), sorted_copy.end());

    bool iffound = false;
    int token_left = 0;
    int token_right = n-1;
    int curr_sum;

    // traverse sorted vector from both ends in order to find a sum
    while(!iffound){
        curr_sum = sorted_copy.at(token_left) + sorted_copy.at(token_right);
        if(curr_sum == money){
            iffound = true;
        }
        else if(curr_sum > money){
            token_right--;
        }
        else{
            token_left++;
        }
    }
    for(int j = 0; j < n; j++){
        if(cost.at(j) == sorted_copy.at(token_left) || cost.at(j) == sorted_copy.at(token_right)){
            cout << j + 1 << " ";
        }
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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
