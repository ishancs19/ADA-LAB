#include <iostream>
using namespace std;

void delay() {
    for(int i = 0; i < 10000000; i++) {
        //delay
    }
}

int partition(int arr[], int left, int right, int pivot) {
    int left_ptr = left;
    int right_ptr = right - 1;
    while(1) {
        while(arr[left_ptr] < pivot) {
            left_ptr++;
        }
        while(arr[right_ptr] >= pivot) {
            right_ptr--;
        }
        if(left_ptr >= right_ptr) {
            break;
        } else {
            swap(arr[left_ptr], arr[right_ptr]);
        }
    }
    swap(arr[left_ptr], arr[right]);
    return left_ptr;
}

void quick_sort(int arr[], int left, int right) {
    if(right - left <= 0) {
        return;
    }
    int pivot = arr[right];
    int partition_point = partition(arr, left, right, pivot);
    quick_sort(arr, left, partition_point - 1);
    quick_sort(arr, partition_point + 1, right);
    delay();
}

int main() {
    clock_t start, end;
    int n;
    cout<<"\nEnter the size of the array: ";
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }

    cout<<"\nUnsorted array: \n";
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }

    start = clock();
    quick_sort(arr, 0, n-1);
    end = clock();

    cout<<"\nSorted array: \n";
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }

    cout<<"\nTime taken for quick sort: "<<float(end-start)/CLOCKS_PER_SEC;

    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[i-1]) {
            cout<<"\nUNSORTED!!!!";
            break;
        }
    }
    return 0;
}
