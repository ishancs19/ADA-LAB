#include<iostream>
#include<time.h>
using namespace std;
void insort(int arr[], int n) {
    int key;
    for(int i = 1; i < n; i++) {
        key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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
    cout<<"\n Elements of the array before sorting: \n";
     for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    start = clock();
    insort(arr, n);
    end = clock();
    cout<<"\n Elements of the array after sorting: \n";
     for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n Time taken for sorting = "<<(float(end-start)/CLOCKS_PER_SEC)<<" seconds";
    return 0;
}
