#include <stdio.h>

using namespace std;

int min(int[] arr, int n){
    int min1 = arr[0];
    int min2 = arr[1];
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < min1){
            min1 = arr[i];
            min2 = min1;
        }
        else if(arr[i] < min2)
        {
            min2 = arr[i];
        }
    }
    return min2;
}

void main{
    int arr[4];
    arr = {2,3,4,5}

    cout<<min(arr,4);
}
