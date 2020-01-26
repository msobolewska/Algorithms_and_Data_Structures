#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int n = s.size();
    cout << "n: " << n << endl;
    int gap_size;
    int counter = 0;
    unordered_map<int, int> HashM;
    string a;
    string b;
    multiset<char> aa;
    multiset<char> bb;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j< n; j++){
            if(s.at(i) == s.at(j)){
                counter++;
                cout << "counter: " << counter << endl;
                HashM[i*1000+i*100+j*10+j] = 1;
                gap_size = j-i-1;

                for(int k = 1; k < gap_size+1; k++){
                    for(int l = i-k; l < i+1; l++){
                        for(int m = j-k; m < j+1; m++){
                            if(l >= 0 && l+k < n && m >= 0 && m+k < n && !HashM[l*1000+                                     (l+k)*100+m*10+m+k]){
                                for(int n = 0; n < k+1; n++){
                                    aa.insert(s.at(l+n));
                                    bb.insert(s.at(m+n));
                                }
                                if(aa == bb){
                                    for(char c : aa){
                                        //cout << c;
                                    }
                                    //cout << endl;
                                    for(char c : bb){
                                        //cout << c;
                                    }
                                    //cout << endl;
                                    HashM[l*1000+(l+k)*100+m*10+m+k]=1;
                                    counter++;
                                    cout << "counter: " << counter << endl;
                                    //cout << "l: " << l << " m: " << m << endl;
                                }
                                aa.clear();
                                bb.clear();
                            }
                        }
                    }
                }

            }
        }
    }
    cout << counter << endl;
    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;

}
