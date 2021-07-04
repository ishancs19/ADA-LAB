#include<iostream>
using namespace std;
int max(int a, int b) {
    return (a>b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int k[n+1][W+1];

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i ==0 || w == 0)
                k[i][w] = 0;
            else if(wt[i - 1] <= w)
                k[i][w] = max(val[i -1] + k[i - 1][w - wt[i - 1]], k[i - 1][w]);
            else
                k[i][w] = k[i-1][w];
        }
    } 
    return k[n][W];  
}

int main() {
    int W, n;
    cout<<"\n Enter capacity of knapsack: ";
    cin>>W;
    cout<<"\n Enter number of items: ";
    cin>>n;
    
    int val[n], wt[n];
    for(int i = 0; i < n; i++) {
        cout<<"\n Enter value and weight of item: ";
        cin>>val[i];
        cin>>wt[i];
    }

    cout<<"\n Solution to knapsack: "<<knapsack(W, wt, val, n);
    return 0;
}
