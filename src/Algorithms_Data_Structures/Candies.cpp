#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    long result = 0;
    vector<int> candies = vector<int>(arr.size(),1);

    for(int i = 1; i < arr.size(); i++){
        if(arr.at(i) > arr.at(i-1)){
            candies.at(i)=candies.at(i-1)+1;
        }
    }

    for(int i = arr.size()-1; i > 0; i--){
        if(arr.at(i) < arr.at(i-1) && candies.at(i) >= candies.at(i-1)){
            candies.at(i-1)=candies.at(i)+1;
        }
    }

    for(int i : candies){
        result += i;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
