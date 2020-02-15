#include <iostream>
#include <math.h>

using namespace std;

int StringToOint(string s);
string IntToString(int input);

int main(){

cout << IntToString(1230) << endl;
cout << IntToString(-123) << endl;
cout << IntToString(0) << endl;
cout << IntToString(1) << endl;

return 0;
}

int StringToOint(string s){
int result = 0;

bool negative = false;
int i = 0;

if(s.at(0) == '-'){
    negative = true;
    i = 1;
}
while(i != s.size()){
    result *= 10;
    result += s.at(i) - '0';
    i++;
}
if(negative){
    result = -result;
}

cout << "string: " << s << " int: " << result << endl;

return result;
}

string IntToString(int input){
    string result = "";
    bool isneg = (input>=0 ? false : true);
    //bool isneg = true;

    int temp = input;
    int left = abs(input);
    int int_0 = int('0');

    do{
        temp = left % 10;
        result = char(temp+int_0)+result;
        left = left/10;
    }while(left > 0 );

    if(isneg){
        result = "-" + result;
    }
    return result;
}
