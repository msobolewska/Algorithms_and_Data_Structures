#include<iostream>

using namespace std;

int FindIndexWr(int arr[], int n, int f);
int FindIndex(int arr[], int start, int en, int f);
int IterBinarySearch(int arr[], int n, int f);

int main(){
    int test[5] = {1,2,3,4,5};
    cout << FindIndexWr(test, 5, 4) << " " << IterBinarySearch(test, 5, 4) << endl;
    return 0;
}

int FindIndexWr(int arr[], int n, int f){
    return FindIndex(arr, 0, n-1 , f);
}
int FindIndex(int arr[], int start, int en, int f){
    if(en < start){
        return -1;
    }
    int half = start+(en-start)/2;
    if(arr[half] == f){
        return half;
    }
    return arr[half] > f ? FindIndex(arr, start, half-1, f) : FindIndex(arr, half+1, en, f);
}

int IterBinarySearch(int arr[], int n, int f){
    int start = 0;
    int en = n-1;
    int diff;
    int half;
    do{
        diff = en - start;
        half = diff / 2 + start;
        if(arr[half] == f){
            return half;
        }
        if(arr[half] > f){
            en = half - 1;
        }
        else{
            start = half + 1;
        }
    }while(diff > -1);
    return -1;
}
