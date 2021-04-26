#include<iostream>
#include<time.h>
using namespace std;
void select_sort(int arr[], int n) {
    int temp, min;
    for(int i = 0; i < n+1; i++){
        min = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    clock_t start, end;
    int n;
    cout<<"\n Enter the size of the array: ";
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
    cout<<"\n Elements of the array BEFORE sorting: ";
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    start = clock();
    select_sort(arr, n);
    end = clock();
    cout<<"\n Elements of the array AFTER sorting: ";
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n Time Taken: "<<(end-start);
    return 0;
}
