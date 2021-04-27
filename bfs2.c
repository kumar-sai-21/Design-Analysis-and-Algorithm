#include <stdio.h>
#include <stdlib.h>

#define max 200
#define white 1
#define grey 2
#define black 3

int size, v, adj[22][22], color[22], q[22], f = 0, r = -1;


int insert(int i)
{
    if (r == max - 1)
    {
        return -1;
    }

    else
    {
        r += 1;
        q[r] = i;
        //printf("\nq[r] is %d", q[r]);
    }

    return 0;
}


int isEmpty()
{
    if (r == -1 || f > r)
    {
        //printf("\n f = %d and r = %d", f, r);
        //printf("\nEmpty");
        return 1;
    }

    //printf("\nnot empty");
    return 0;
}


int delete()
{
    int deleted;

    if (isEmpty())
    {
        printf("\nQueue is empty !");
        exit(0);
    }

    deleted = q[f];
    f += 1;

    //printf("\ndeleted is %d", deleted);

    return deleted;
}


void bfs(int v1)
{
    int i, u;

    for (i = 0; i < size; i++)
    {
        color[i] = white;
    }

    color[v1] = grey;
    insert(v1);

    while (!isEmpty())
    {
        //printf("\ninside while");
        u = delete();

        printf("%d ", u);

        for (i = 0; i < size; i++)
        {
            //printf("\nu is %d", u);
            if (adj[u][i] == 1 && color[i] == white)
            {
                color[i] = grey;
                insert(i);
                //printf("\ninside if");
            }
        }

        color[u] = black;
    }
}


int main()
{
    int i, max_edge, origin, destin;

    printf("Enter the number of vertices - ");
    scanf("%d", &size);

    max_edge = size * (size - 1);

    for (i = 0; i <= max_edge; i++)
    {
        printf("\nEnter edge(a b) %d. (-1 -1) to quit - ", i);
        scanf("%d%d", &origin, &destin);

        if (origin == -1 || destin == -1)
        {
            break;
        }

        else if(origin >= size || destin >= size || origin < 0 || destin < 0)
		{
			printf("\nInvalid edge!");
			i--;
		}

		else
		{
			adj[origin][destin] = 1;
            //adj[destin][origin] = 1;
		}
    }

    printf("\n");

    int j;
    for(i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", adj[i][j]);
        }

        printf("\n");
    }

    printf("\nEnter Start Vertex for BFS - ");
	scanf("%d", &v);

    bfs(v);
}
