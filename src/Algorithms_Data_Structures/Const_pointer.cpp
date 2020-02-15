#include <iostream>

using namespace std;

void Char_Const_Char();

int main(){

Char_Const_Char();

return 0;
}

void Char_Const_Char(){
/* Explain differences between constant pointer and pointer constant */
char a = 'a';
char b = 'b';

/* constant pointer */
/* can change pointing memory location, cannot change the content */

const char *chrptr1 = &a;

cout << "chrptr1 is located at " << chrptr1 << endl;

//*chrptr1 = 'c'; // should rise an error

cout << "chrptr1 is located at " << chrptr1 << endl;

chrptr1++;

cout << "chrptr1 is located at " << chrptr1 << endl;

/* pointer constant */
/* cannot change pointing memory location, can change the content */

char *const chrptr2 = &b;

cout << "chrptr2 is located at " << chrptr2 << endl;

*chrptr2 = 'c';

cout << "chrptr2 is located at " << chrptr2 << endl;

//chrptr2++;// should rise an error

cout << "chrptr2 is located at " << chrptr2 << endl;
}
