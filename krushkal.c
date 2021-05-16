//SAI KUMAR SATAPATHY
//ROLL NO-04

#include<stdio.h>
#include<stdlib.h>
#define INFINITY 9999
#define MAX 20


int find(int u,int parent[])
{
    int i=u;
    while(parent[i]!=-1)
    {
       i=parent[i];
    }
    return i;

}
int makeunion(int u,int v,int parent[])
{
    if(u!=v)
    {
        parent[v]=u;
       return 1;
    }
    return 0;
}

void kruskal(int cost[MAX][MAX],int n)
{
    int i,j,min=INFINITY;
    int a,b,u,v;
    int parent[n];int tcost=0,count=0;

    for(i=0;i<n;i++)
    {
        parent[i]=-1;
    }


while(count<n-1)
{
     min=INFINITY;
  for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                a=i;b=j;
                u=i;v=j;
            }
        }
    }

    u=find(u,parent);
    v=find(v,parent);
    if(makeunion(u,v,parent))
    {
        printf("from %d to %d with cost - %d \n",a,b,min);
        tcost=tcost+min;
        count++;
    }
    cost[a][b]=cost[b][a]=INFINITY;

}
    printf("minimum cost is :%d \n",tcost);
}
void main()
{
	printf("enter the no. of vertices \n");
    int n;
    scanf("%d",&n);

    int i,j;
    int graph[MAX][MAX];
       for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            graph[i][j]=INFINITY;
        }
    }
    while (1)
    {
        int source,destination,weight;
        printf("Enter the Source, destination and weight \t enter the -1 -1 -1 to exit \n");
        scanf("%d %d %d",&source,&destination,&weight);
        if(source ==-1 && destination == -1)
            break;
        else{
            graph[source][destination]=weight;
             graph[destination][source]=weight;
        }

    }


	kruskal(graph,n);

}
