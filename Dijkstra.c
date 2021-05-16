//SAI KUMAR SATAPATHY
//ROLL NO-04

#include<stdio.h>
#include<stdlib.h>
#define INFINITY 9999
#define MAX 10


void dijkstra(int graph[MAX][MAX],int n,int startnode)
{

    int distance[MAX];
	int visited[MAX],mindistance,nextnode,i,j;


	//initializing all distance as per cost
	for(i=0;i<n;i++)
	{
		distance[i]=graph[startnode][i];
		visited[i]=0;
	}

	distance[startnode]=0;
	visited[startnode]=1;


	for(j=0;j<n-1;j++)
	{
		mindistance=INFINITY;

		//Finding minimum cost node
		for(i=0;i<n;i++)
			if(distance[i]<mindistance && !visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}

			//updating path from minimum cost node
      //relaxation
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+graph[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+graph[nextnode][i];

					}

	}

	//print the path and distance of each node
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("%d-> %d = %d \n",startnode,i,distance[i]);
        }
}

void main()
{
	printf("enter the no. of vertices \n");
    int n;
    scanf("%d",&n);
    printf("enter the Source to begin\n");
    int s;
    scanf("%d",&s);
    int i,j;
    int graph[MAX][MAX];
       for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            graph[i][j]=INFINITY;
        }
    }
    printf("Enter the Source, destination and weight \t enter the -1 -1 -1 to exit \n");
    while (1)
    {
        int source,destination,weight;
        scanf("%d %d %d",&source,&destination,&weight);
        if(source ==-1 && destination == -1)
            break;
        else{
            graph[source][destination]=weight;
        }

    }
	dijkstra(graph,n,s);

 
}
