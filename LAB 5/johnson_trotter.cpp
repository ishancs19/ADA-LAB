#include<iostream>
using namespace std;

int fact(int n) {
    int res = 1;
    for (int i = 1; i<= n; i++) {
        res *= i;
    }
    return res;
}

int get_mobile(int a[], bool dir[], int n) {
    int prev_mobile = 0, mobile = 0;
    for(int i = 0; i < n; i++) {
        if(dir[a[i]-1] == 0 && i!=0) {
            if(a[i] > a[i-1] && a[i] > prev_mobile) {
                mobile = a[i];
                prev_mobile = mobile;
            }
        }

        if(dir[a[i]-1] == 1 && i != n-1) {
            if(a[i] > a[i+1] && a[i] > prev_mobile) {
                mobile = a[i];
                prev_mobile = mobile;
            }
        }
    }
    if(mobile == 0 && prev_mobile == 0) 
        return 0;
    else
        return mobile;
}

int search_mobile_postion(int a[], int n, int mobile) {
    for(int i = 0; i < n; i++) {
        if (a[i] == mobile) {
            return i+1;
        }
    }
}

void print_one_permutation(int a[], bool dir[], int n) {
    int mobile = get_mobile(a, dir, n);
    int mobile_pos = search_mobile_postion(a, n, mobile);

    if(dir[a[mobile_pos-1]-1] == 0) {
        swap(a[mobile_pos - 1], a[mobile_pos - 2]);
    }
    else if (dir[a[mobile_pos - 1] - 1] == 1) {
        swap(a[mobile_pos], a[mobile_pos - 1]);
    }

    for(int i = 0; i < n; i++) {
        if(a[i] > mobile) {
            if(dir[a[i] - 1] == 1) {
                dir[a[i] - 1] = 0;
            }
            else if (dir[a[i] - 1] == 0) {
                dir[a[i] - 1] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout<<a[i];
    }
    cout<<" ";
}

void print_permutation(int n) {
    int a[n];
    bool dir[n];
    for(int i = 0; i < n; i++) {
        a[i] = i+1;
        cout<<a[i];
    }
    cout<<" ";
    for(int i = 0; i < n; i++) {
        dir[i] = 0;
    }
    for(int i = 0; i < fact(n); i++) {
        print_one_permutation(a, dir, n);
    }
}

int main() {
    int n;
    cout<<"Enter the number of permutations to be generated: ";
    cin>>n;
    print_permutation(n);
    return 0;
}
