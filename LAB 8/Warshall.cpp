#include<iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a:b;
}

void display(int a[10][10], int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j<= n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void warshall(int a[10][10], int n) {
    int i, j, k;
    for(k = 1; k <= n; k++) {
        for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        a[i][j] = max(a[i][j], a[i][k] && a[k][j]);
        cout<<"P("<<k<<") : "<<endl;
        display(a, n);
    }
}

int main() {
    int a[10][10];
    int n, e, u, v;
    cout<<"\n Enter number of vertices: ";
    cin>>n;
    cout<<"\n Enter adjacency matrix: ";
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) 
    cin>>a[i][j];

    cout<<"\n Input Matrix: \n";
    display(a, n);

    warshall(a, n);
    return 0;
}
