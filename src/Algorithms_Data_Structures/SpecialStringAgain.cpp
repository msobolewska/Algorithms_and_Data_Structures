#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    if(n == 0){
        return 0;
    }

    if(n == 1){
        return 1;
    }

    long answer_a;
    long answer_b = 0;

    // all characters are the same

    vector<int> repeatitions(n);
    repeatitions[0] = 1;
    answer_a = 1;

    for(int i = 1; i < n; i++){
        if(s.at(i) == s.at(i-1)){
            repeatitions[i] = repeatitions[i-1]+1;
            answer_a += repeatitions[i];
        }
    }

    // all characters except the middle one are the same

    if(n == 2){
        return answer_a;
    }

    answer_b = 0;

    int left;
    int prev_let;
    int right;
    int token;

    left = 0;
    righ = 2;
    token = 1;
    while(token < n){
        prev_let = left;
        while(left >= 0 && right < n && s.at(left) != s.at(token) && s.at(left) == s.at(prev_let) && s.at(left) == s.at(right)){
            answer_b++;
            prev_left = left;
            left--;
            right++;
        }
        token++;
        left = token - 1;
        right = token + 1;
    }

    return answer_b + answer_a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
