#include<iostream>
using namespace std;

void merge(int arr[], int p, int q, int r) {
    int n1 = (q - p) + 1;
    int n2 = r - q;
    int L[n1], M[n2];
    for(int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }
    for(int j = 0; j < n2; j++) {
        M[j] = arr[(q+1) + j];
    }
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while(i < n1 && j < n2) {
        if(L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
     while(j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) {
    if(l < r) {
        int m = (l + (r - 1)) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
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
    merge_sort(arr, 0, n);
    end = clock();

    cout<<"\nSorted array: \n";
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }

    cout<<"\nTime taken for merge sort: "<<(float(end-start)/CLOCKS_PER_SEC);
    return 0;
}
