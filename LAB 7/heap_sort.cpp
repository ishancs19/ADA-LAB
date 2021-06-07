#include <iostream>
using namespace std;

void delay() {
    for(int i = 0; i < 10000000; i++) {
        //delay
    }
}


void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heap_sort(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for(int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    
    delay();
}


int main() {
    clock_t start, end;
    int n;
    cout<<"\nEnter the size of the array: ";
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % (n*10);
    }

    cout<<"\nUnsorted array: \n";
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }

    start = clock();
    heap_sort(arr, n);
    end = clock();

    cout<<"\nSorted array: \n";
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }

    cout<<"\n Time taken: "<<float(end-start)/CLOCKS_PER_SEC;

    return 0;
}
