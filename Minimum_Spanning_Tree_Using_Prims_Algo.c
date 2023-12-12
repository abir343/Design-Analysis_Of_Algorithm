#include<stdio.h>
#include<stdlib.h>

#define INFINITY 9999
#define MAX 20

int G[MAX][MAX],spanning[MAX][MAX],n;


int Prims() {
	int cost[MAX][MAX];
	int source,destination,min_distance,distance[MAX],from[MAX];
	int visited[MAX],no_of_edges,i,min_cost,j;
	
	//create cost[][] matrix,spanning[][]
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
				spanning[i][j]=0;
		}
    }
		
	//initialise visited[],distance[] and from[]
	distance[0]=0;
	visited[0]=1;
	
	for(i=1;i<n;i++) {
		distance[i]=cost[0][i];
		from[i]=0;
		visited[i]=0;
	}
	
	min_cost=0;		//cost of spanning tree
	no_of_edges=n-1;		//no. of edges to be added
	
	while(no_of_edges>0) {
		//find the vertex at minimum distance from the tree
		min_distance=INFINITY;
		for(i=1;i<n;i++) {
			if(visited[i]==0&&distance[i]<min_distance) {
				destination=i;
				min_distance=distance[i];
			}
        }

		source=from[destination];
		
		//insert the edge in spanning tree
		spanning[source][destination]=distance[destination];
		spanning[destination][source]=distance[destination];
		no_of_edges--;
		visited[destination]=1;
		
		//updated the distance[] array
		for(i=1;i<n;i++) {
			if(visited[i]==0&&cost[i][destination]<distance[i]) {
				distance[i]=cost[i][destination];
				from[i]=destination;
			}
        }
		
		min_cost=min_cost+cost[source][destination];
	}
	
	return(min_cost);
}

int main() {
	int i,j,total_cost;
	printf("Enter no. of vertices : ");
	scanf("%d",&n);
	
	printf("\nEnter the adjacency matrix : \n");
	
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			scanf("%d",&G[i][j]);
        }
    }
	
	total_cost=Prims();
	printf("\nSpanning tree matrix : \n");
	
	for(i=0;i<n;i++) {
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d\t",spanning[i][j]);
	}
	
	printf("\n\nTotal cost of spanning tree = %d.",total_cost);
	return 0;
}
