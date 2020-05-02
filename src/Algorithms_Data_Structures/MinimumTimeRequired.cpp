#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minTime function below.
long minTime(vector<long> machines, long goal) {
    long lowest = 1E9;
    long biggest = 1;
    for(long l : machines){
        if(l > biggest){
            biggest = l;
        }
        if(l < lowest){
            lowest = l;
        }
    }
    long lower_limit = lowest * ceil(goal / (float)machines.size());
    long upper_limit = biggest * ceil(goal / (float)machines.size());
    long diff = upper_limit - lower_limit;
    long middle;
    long result_l;
    long result_r;

    while(diff > 0){
        middle = lower_limit + diff / 2.;
        result_l = 0;
        result_r = 0;
        for(long l : machines){
            result_r += middle / l;
            result_l += (middle-1 >= 0) ? ((middle-1) / l) : 0;
        }
        if(result_r >= goal && result_l < goal){
            upper_limit = -1; // we have solution
        }
        else if(result_r >= goal){
            upper_limit = middle;
        }
        else if(result_r < goal){
            lower_limit = middle;
        }
        diff = upper_limit - lower_limit;
    }
    return middle;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nGoal_temp;
    getline(cin, nGoal_temp);

    vector<string> nGoal = split_string(nGoal_temp);

    int n = stoi(nGoal[0]);

    long goal = stol(nGoal[1]);

    string machines_temp_temp;
    getline(cin, machines_temp_temp);

    vector<string> machines_temp = split_string(machines_temp_temp);

    vector<long> machines(n);

    for (int i = 0; i < n; i++) {
        long machines_item = stol(machines_temp[i]);

        machines[i] = machines_item;
    }

    long ans = minTime(machines, goal);

    fout << ans << "\n";

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
