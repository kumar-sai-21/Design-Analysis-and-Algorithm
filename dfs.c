#include<stdio.h>
#define max 20
int n,i,j, top=-1;
char color[max];
int time;
int pi[max],d[max],f[max],visited[max];
void dfs(int ,int [][max]);
int main()
{
    int v,a[max][max],k;
    printf("Enter the no of vertex");
    scanf("%d",&n);
    printf("Enter the adjacency matrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the starting vertex");
    scanf("%d",&v);

    for(i=0;i<n;i++)
    {
        color[i]='w';
        pi[i]=-1;
        visited[i]=0;
    }
    time=0;
    for(i=0;i<n;i++){
        if(color[i]=='w')
        {
            dfs(i,a);
        }
    }
    // for(i=0;i<n;i++)
    // {
    //     if(visited[i]==0)
    //     {
    //         dfs(i,a);
    //     }
    // }

}
void dfs(int u, int a[][max])
{
    int k;
    color[u]='g';
    visited[u]=1;
    printf("%d \t", u);
    time=time+1;
    d[u]=time;
    for(k=0;k<n;k++)
    {
        if(a[u][k]==1)
        {
            if(color[k]=='w')
            {
                pi[k]=u;
                dfs(k,a);
            }
        }
    }
    color[u]='b';
    f[u]=time;

}
