#include<stdio.h>
#include<stdlib.h>
# define max 10
struct vertex{
	int d, pi;
	char c;
}V[max];
int q[max], f = 0, r = 0, v, m[max], c= 0;
void bfs(int m[][max], int);
void print_path(int, int);
void enqueue(int);
int dequeue();
void order(int);
void display();
int main()
{
	printf("Number of Vertices : ");
	scanf("%d", &v);
	int am[max][max], i, j, s, d;
	printf(" \n enter the adjacency matrix for the graph: \n");
	for(i = 0; i< v; i++)
		for(j = 0; j < v; j++)
			scanf("%d", &am[i][j]);
	printf("\n the entered adjacency matrix is: \n");
	for(i = 0; i< v; i++)
	{
		for(j = 0; j< v; j++)
			printf("%d  ", am[i][j]);
		printf("\n");
	}
	printf(" \n enter the source vertex: ");
	scanf("%d", &s);
	bfs(am, s);

	display();
	return 0;
}
void print_path(int s, int d)
{
	if(d == s)
		printf("%d  ", s);
	else if(V[d].pi == -1)
		printf("\n no path exists from %d to %d\n", s, d);
	else
	{
		print_path(s, V[d].pi);
		printf("%d  ", d);
	}
}
void bfs(int g[max][max], int s)
{
	int i, j, u;
	for(i = 0; i<v; i++)
	{
		if(i != s)
		{
			V[i].c = 'w';
			V[i].d = 999999;
			V[i].pi = -1;
		}
	}
	V[s].c = 'g';
	V[s].d = 0;
	V[s].pi = -1;
	enqueue(s);
	while(f != r)
	{
		u = dequeue();
		order(u);
		for(i = 0; i< v; i++)
		{
			if(g[u][i] == 1)
			{
				if(V[i].c == 'w')
				{
					V[i].c = 'g';
					V[i].d = V[u].d + 1;
					V[i].pi = u;
					enqueue(i);
				}
			}
		}
		V[u].c = 'b';
	}
}
void order(int s)
{
	m[c++] = s;
}
void display()
{
	printf("\n the values from the queue in order: \n");
	for(int i = 0; i < c; i++)
		printf("%d   ", m[i]+1);
}
void enqueue(int s)
{
	if(r != max-1)
		q[r++] = s;
	else
	{
		printf("\n overflow ");
		return;
	}
}
int dequeue()
{
	if(f == r)
	{
		printf(" \n underflow \n");
		return 0;
	}
	return q[f++];
}
