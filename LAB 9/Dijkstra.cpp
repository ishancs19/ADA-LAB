#include<iostream>
using namespace std;
int V;

int minimum_distance(int dist[], bool sptSet[]) {
    int min = 9999 , min_index;
    for(int v = 0; v < V; v++) {
        if(sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void print_sol(int dist[]) {
    cout<<"\nVertex \t \t Distance from Source";
    for(int i = 0; i < V; i++) {
        cout<<"\n"<<i<<" \t \t "<<dist[i];
    }
}

void dijkstra(int a[9][9], int src) {
    int dist[V];
    bool sptSet[V];

    for(int i = 0; i < V; i++) {
        dist[i] = 9999;
        sptSet[i] = false;
    }
    dist[src] = 0;

    for(int count = 0; count < V-1; count++) {
        int u = minimum_distance(dist, sptSet);
        sptSet[u] = true;

        for(int v = 0; v < V; v++) {
            if(!sptSet[v] && a[u][v] && (dist[u] + a[u][v]) < dist[v]) {
                dist[v] = dist[u] + a[u][v];
            }
        }
    }
    print_sol(dist);
}

int main() {
    V = 9;
    int a[9][9];
    cout<<"\n Enter adjacency matrix of weighted graph: ";
    for(int i = 0; i < V; i++)
    for(int j = 0; j < V; j++) {
        cin>>a[i][j];
    }
    dijkstra(a, 0);
    return 0;
}
