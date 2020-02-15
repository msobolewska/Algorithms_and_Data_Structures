#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int Find_DNA_Health(string d, int first, int last, vector<string> genes, vector<int> health);

int main(){

int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string genes_temp_temp;
    getline(cin, genes_temp_temp);

    vector<string> genes_temp = split_string(genes_temp_temp);

    vector<string> genes(n);

    for (int i = 0; i < n; i++) {
        string genes_item = genes_temp[i];

        genes[i] = genes_item;
    }

    string health_temp_temp;
    getline(cin, health_temp_temp);

    vector<string> health_temp = split_string(health_temp_temp);

    vector<int> health(n);

    for (int i = 0; i < n; i++) {
        int health_item = stoi(health_temp[i]);

        health[i] = health_item;
    }

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int healthiest = 0;
    int unhealthiest = INT_MAX;
    int temp;

    int first;
    int last;
    string d;

    for (int s_itr = 0; s_itr < s; s_itr++) {

        string firstLastd_temp;
        getline(cin, firstLastd_temp);

        vector<string> firstLastd = split_string(firstLastd_temp);

        first = stoi(firstLastd[0]);

        last = stoi(firstLastd[1]);

        d = firstLastd[2];

        //temp = Find_DNA_Health(d, first, last, genes, health);

        //if(temp < unhealthiest){
        //    unhealthiest = temp;
        //}
        //if(temp > healthiest){
        //    healthiest = temp;
       // }

    }

    temp = Find_DNA_Health(d, first, last, genes, health);

    cout << temp << endl;

    cout << unhealthiest << " " << healthiest << endl;

    return 0;

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

int Find_DNA_Health(string d, int first, int last, vector<string> genes, vector<int> health){
    int result = 0;

    map<string, vector<pair<int, int> > > DNA_Map;//gene, <position, health>, <position, health>, ...

    for(int i = first; i <= last; i++){
        DNA_Map[genes.at(i)].push_back(pair<int, int>(i, health.at(i)));
    }

    string temp;
    size_t found;
    int iter;

    for(map<string, vector<pair<int, int> > >::iterator it = DNA_Map.begin(); it != DNA_Map.end(); it++){
        temp = d;
        found = temp.find(it->first);
        iter = 0;

        while(found != string::npos){
            cout << "temp: " << temp << endl;
            iter++;
            temp.erase(found);
            found = temp.find(it->first);
        }
        if(iter){
            for(vector<pair<int, int> >::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
                if(it2-> second > first && it2-> second <= last){
                    cout << result << endl;
                    result += it2->first * iter;
                }
            }
        }
    }

    return result;
}
