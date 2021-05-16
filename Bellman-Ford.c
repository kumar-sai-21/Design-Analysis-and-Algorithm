//SAI KUMAR SATAPATHY
//ROLL NO-04

#include<stdio.h>
#include<stdlib.h>
#define max 20
#define infinite 99999

void bellman(int adj[max][max],int n,int source)
{

 int distance[n],i,j,k;

 // initializing the distance of each path as infinite
 for(i=0;i<n;i++)
 {
     distance[i]=infinite;
 }
 distance[source]=0; //set the source as 0 and other to infinite


 // Looping through n-1 times to check and update the shortest path
 for(i=0;i<n;i++)
  {
      for (j=0;j<n;j++)
      {
          if(adj[i][j]!=infinite)
          {
           if( distance[i]+adj[i][j]<distance[j])
           {
               distance[j]=distance[i]+adj[i][j];
            //    printf("distance of %d is  %d  and weight is %d and new distance of %d is %d \n",i,distance[i],adj[i][j],j,distance[j]);
           }
          }
          else{
            //   printf(" infinite at %d %d\n",i,j);
              for(k=i+1;k<n;k++)
              {
                  if(adj[k][j]!=infinite && k!=j)
                  {
                      if(distance[k]+adj[k][j]<distance[j])
                      {
                          distance[j]=distance[k]+adj[k][j];
                          break;
                        //   printf("distance of %d is  %d  and weight is %d and new distance of %d is %d \n",k,distance[k],adj[k][j],j,distance[j]);
                      }
                  }

              }
          }
      }
  }

for(i=0;i<n;i++)
{
     if( distance[i]+adj[i][j]<distance[j])
           {
               distance[j]=distance[i]+adj[i][j];
            //    printf("distance of %d is  %d  and weight is %d and new distance of %d is %d \n",i,distance[i],adj[i][j],j,distance[j]);
                printf("the graph contains negetive cycle \n");
                exit(1);
           }
}
//Printing the shortest path
printf(" the shortest paths are :\n");
for(i=0;i<n;i++)
{
    printf("%d -> %d  = %d\n",source,i,distance[i]);
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
    int adj[max][max];
       for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            adj[i][j]=infinite;
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
            adj[source][destination]=weight;
        }

    }

    bellman(adj,n,s);
}
