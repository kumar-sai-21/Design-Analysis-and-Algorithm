//SAI KUMAR SATAPATHY
//ROLL NO-04

#include<stdio.h>
#define INFINITY 9999
#define MAX 20

void prims(int graph[MAX][MAX],int n)
{
    int visited[n],i,j,count=1,min=INFINITY,tcost=0;
    int next=0,min_node;
    int path[n];
    for(i=0;i<n;i++)
       visited[i]=0;

    path[0]=0;
    printf("%d",next);
    while (count<n)
    {
        min=INFINITY;
        for(i=0;i<n;i++)
        {

            if(graph[next][i] && !visited[i])
            {

               if(graph[next][i]<min)
               {
                   min=graph[next][i];
                   min_node=i;

               }
            }
        }
        next=min_node;
        visited[next]=1;count++;
        tcost+=min;
        printf(" -> %d  cost - %d \n",next,min);
        printf("%d ",next);

    }
    printf("\ntotal cost %d\n",tcost);

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
            graph[i][j]=0;
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
        }

    }
	prims(graph,n);

}
