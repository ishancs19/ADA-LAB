#include<iostream>
#include<time.h>
using namespace std;
void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
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
    bubble_sort(arr, n);
    end = clock();
    cout<<"\n Elements of the array AFTER sorting: ";
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n\n Time Taken: "<<(end-start);
    return 0;
}
