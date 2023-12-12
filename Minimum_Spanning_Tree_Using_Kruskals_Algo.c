#include<stdio.h>
#define MAX 30

typedef struct Edge {
	int source, destination, weight;
}Edge;

typedef struct Edgelist {
	Edge edges[MAX];
	int n;
}Edgelist;

Edgelist edgelist;

int Graph[MAX][MAX],n;
Edgelist spanlist;

int Find(int belongs[],int vertexno) {
	return(belongs[vertexno]);
}

void Union(int belongs[],int c1,int c2) {
	int i;
	
	for(i=0;i<n;i++)
		if(belongs[i]==c2)
			belongs[i]=c1;
}

void Sort() {
	int i,j;
	Edge temp;
	
	for(i=1;i<edgelist.n;i++)
		for(j=0;j<edgelist.n-1;j++)
			if(edgelist.edges[j].weight>edgelist.edges[j+1].weight) {
				temp=edgelist.edges[j];
				edgelist.edges[j]=edgelist.edges[j+1];
				edgelist.edges[j+1]=temp;
			}
}

void Kruskal() {
	int belongs[MAX],i,j,cno1,cno2;
	edgelist.n=0;

	for(i=1;i<n;i++) {
		for(j=0;j<i;j++) {
			if(Graph[i][j]!=0) {
				edgelist.edges[edgelist.n].source=i;
				edgelist.edges[edgelist.n].destination=j;
				edgelist.edges[edgelist.n].weight=Graph[i][j];
				edgelist.n++;
			}
		}
    }
	Sort();
	
	for(i=0;i<n;i++)
		belongs[i]=i;
	
	spanlist.n=0;
	
	for(i=0;i<edgelist.n;i++) {
		cno1=Find(belongs,edgelist.edges[i].source);
		cno2=Find(belongs,edgelist.edges[i].destination);
		
		if(cno1!=cno2) {
			spanlist.edges[spanlist.n]=edgelist.edges[i];
			spanlist.n=spanlist.n+1;
			Union(belongs,cno1,cno2);
		}
	}
}

void Print() {
	int i,cost=0;
	
	for(i=0;i<spanlist.n;i++) {
		printf("\n%d\t%d\t%d",spanlist.edges[i].destination,spanlist.edges[i].source,spanlist.edges[i].weight);
		cost=cost+spanlist.edges[i].weight;
	}

	printf("\n\nCost of the spanning tree = %d.",cost);
}

int main() {
	
	printf("\nEnter number of vertices : ");
	
	scanf("%d",&n);
	
	printf("\nEnter the adjacency matrix : \n");
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&Graph[i][j]);
			
	Kruskal();
	Print();
	return 0;
}

