#include<stdio.h>
#define size 20
#define true 1
#define false 0

int queue[size], visit[20], rear = -1, front = 0, n, s, adj[20][20], flag = 0;

void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return(queue[front++]);
}

int isEmpty() {
    if(rear < front) {
        return 1;
    }
    else {
        return 0;
    }
}

void BFS (int v){
	int w;
	visit[v] = 1;
	enqueue(v);
	while(!isEmpty()) {
		v = dequeue();
		for(w = 1; w <= n; w++){
		   if((adj[v][w] == 1) && (visit[w] == 0)) {
				  visit[w] = 1;
				  flag = 1;
				  printf("%d\t", w);
				  enqueue(w);
		   }
		}
	}
}

void main() {
    int v, w;
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(v = 1; v <= n; v++){
      for(w = 1;w <= n; w++)
       scanf("%d", &adj[v][w]);
    }
    printf("Enter the start vertex: ");
    scanf("%d", &s);
    printf("Reachability of vertex %d\n", s);
    for(v = 1; v <= n; v++){
        visit[v] = 0;
	}
    BFS(s);
    if(flag == 0){
      printf("No path found...\n");
    }
}
