#include<iostream>
using namespace std;

int main() {
    int v;
    cout<<"\n Enter number of vertices in graph: ";
    cin>>v;
    int G[v][v];
    cout<<"\n Enter weighted adjacency matrix: ";
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            cin>>G[i][j];
        }
    }
    int no_edge = 0, selected[v];
    for(int i = 0; i < v; i++) {
        selected[i] = 0;
    }
    selected[0] = 1;
    int x, y;
    cout<<"\n EDGE "<<" : "<<" WEIGHT";
    while(no_edge < v-1) {
        int min = 999;
        x = 0;
        y = 0;
        for(int i = 0; i < v; i++){
            if(selected[i]) {
                for(int j = 0; j < v; j++) {
                    if(!selected[j] && G[i][j]) {
                        if(min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout<<"\n "<<x<<" -> "<<y<<" : " <<G[x][y];
        selected[y] = 1;
        no_edge++;
    }
    return 0;
}
