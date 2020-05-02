#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the triplets function below.
long triplets(vector<int> a, vector<int> b, vector<int> c) {
    set<int> as;
    set<int> bs;
    set<int> cs;

    vector<int> ass;
    vector<int> bss;
    vector<int> css;

    for(int i : a){
        as.insert(i);
    }

    for(int i : as){
        ass.push_back(i);
    }

    for(int i : b){
        bs.insert(i);
    }

    for(int i : bs){
        bss.push_back(i);
    }

    for(int i : c){
        cs.insert(i);
    }

    for(int i : cs){
        css.push_back(i);
    }

    long result = 0;
    long n_ass;
    long n_css;

    int diff;
    int upper;
    int lower;
    int middle;

    if(ass.at(0) > bss.back() || css.at(0) > bss.back()){
        return 0;
    }

    for(int i : bss){
        //ass
        lower = 0;
        upper = ass.size();
        n_ass = -1;
        diff = upper;
        if(ass.front() <= i){
            while(n_ass < 0){
                middle = lower + diff / 2;
                if(ass.at(middle) <= i && ( middle + 1 == ass.size() || ((middle + 1) < ass.size() && ass.at(middle+1) > i))){
                    n_ass = middle+1;
                }
                else if(ass.at(middle) > i){
                    upper = middle - 1;
                }
                else{
                    lower = middle + 1;
                }
                diff = upper - lower;
            }
        }
        else{
            n_ass = 0;
        }
        lower = 0;
        upper = css.size();
        n_css = -1;
        diff = upper;
        if(css.front() <= i){
            while(n_css < 0){
                middle = lower + diff / 2;
                if(css.at(middle) <= i && ( middle + 1 == css.size() || ((middle + 1) < css.size() && css.at(middle+1) > i))){
                    n_css = middle+1;
                }
                else if(css.at(middle) > i){
                    upper = middle - 1;
                }
                else{
                    lower = middle + 1;
                }
                diff = upper - lower;
            }
        }
        else{
            n_css = 0;
        }
        result += n_ass * n_css;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string lenaLenbLenc_temp;
    getline(cin, lenaLenbLenc_temp);

    vector<string> lenaLenbLenc = split_string(lenaLenbLenc_temp);

    int lena = stoi(lenaLenbLenc[0]);

    int lenb = stoi(lenaLenbLenc[1]);

    int lenc = stoi(lenaLenbLenc[2]);

    string arra_temp_temp;
    getline(cin, arra_temp_temp);

    vector<string> arra_temp = split_string(arra_temp_temp);

    vector<int> arra(lena);

    for (int i = 0; i < lena; i++) {
        int arra_item = stoi(arra_temp[i]);

        arra[i] = arra_item;
    }

    string arrb_temp_temp;
    getline(cin, arrb_temp_temp);

    vector<string> arrb_temp = split_string(arrb_temp_temp);

    vector<int> arrb(lenb);

    for (int i = 0; i < lenb; i++) {
        int arrb_item = stoi(arrb_temp[i]);

        arrb[i] = arrb_item;
    }

    string arrc_temp_temp;
    getline(cin, arrc_temp_temp);

    vector<string> arrc_temp = split_string(arrc_temp_temp);

    vector<int> arrc(lenc);

    for (int i = 0; i < lenc; i++) {
        int arrc_item = stoi(arrc_temp[i]);

        arrc[i] = arrc_item;
    }

    long ans = triplets(arra, arrb, arrc);

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
