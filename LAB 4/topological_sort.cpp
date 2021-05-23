#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"\n Enter the number of vertices: ";
    cin>>n;
    int arr[n][n], indegree[n], count, flag[10];
    cout<<"\n Enter the adjacency matrix: ";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        indegree[i] = 0;
        flag[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            indegree[i] += arr[j][i];
        }
    }
    cout<<"Topological order = ";
    while(count < n){
        for(int k = 0; k < n; k++){
            if((indegree[k] == 0) && (flag[k] == 0)){
                cout<<k+1<<" ";
                flag[k] = 1;
            }
            for(int i = 0; i < n; i++){
                if(arr[i][k] == 1)
                    indegree[k]--;
            }
        }
        count++;
    }
    return 0;
}
