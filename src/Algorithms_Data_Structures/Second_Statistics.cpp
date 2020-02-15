#include <stdio.h>
#include <iostream>

using namespace std;

int min(int arr[], int n){
    int min1 = arr[0];
    int min2 = arr[1];
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < min1){
            min2 = min1;
            min1 = arr[i];
        }
        else if(arr[i] < min2)
        {
            min2 = arr[i];
        }
    }
    return min2;
}

int main(){
    int arr[4];
    arr[0] = 2;
    arr[1] = 3;
    arr[2] = 6;
    arr[3] = 9;

    cout<<min(arr,4);

    return 0;
}
