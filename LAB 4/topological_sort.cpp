#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"\n Enter the number of vertices: ";
    cin>>n;
    int arr[n][n], indegree[n];
    cout<<"\n Enter the adjacency matrix: ";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        indegree[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            indegree[i] += arr[j][i];
        }
    }
    
}
