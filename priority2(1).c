#include<stdio.h>
#include<stdlib.h>
# define max 20
void insert(int [], int);
void increase_key(int [], int, int);
int extract_max(int []);
void heapify(int [], int);
void print(int []);
int heapsize;
int main()
{
	int ch, n, k;
	int a[max];
	heapsize = -1;
	while(true){
		printf(" 1- INSERT \n 2- INCREASE KEY \n 3 - EXTRACT \n 4- PRINT \n5 - EXIT\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf(" enter the number to be inserted : ");
				scanf("%d", &n);
				insert(a, n);
				break;
			case 2:
				printf(" \n enter the actual key :");
				scanf("%d", &n);
				printf(" \n enter the increased key: ");
				scanf("%d", &k);
				increase_key(a, n, k);
				break;
			case 3:
				n = extract_max(a);
				printf("\n extracted : %d\n", n);
				break;
			case 4:
				print(a);
				break;
			case 5:
				exit(0);
			default:
				printf(" invalid input \n");
		}
	}
	return 0;
}
void heapify(int a[], int i)
{
	int l, r, largest = i, t;
	l = 2 * i + 1;
	r = 2 * i + 2;
	if(l <= heapsize && a[l] >= a[i])
		largest = l;
	if(r <= heapsize && a[r] >= a[largest])
		largest = r;
	if(largest != i)
	{
		t = a[i];
		a[i] = a[largest];
		a[largest] = t;
		heapify(a, largest);
	}
}
void increase_key(int a[], int n, int k)
{
	int i, t, p;
	for(i=0; i<=heapsize; i++)
		if(a[i] != n)
			continue;
		else
			break;
	if(k < a[i] || i>heapsize)
	{
		printf("error \n");
		return;
	}
	a[i] = k;
	p = (i-1)/2;
	while(i> 0 && p >= 0 && a[p] < a[i])
	{
		t = a[p];
		a[p] = a[i];
		a[i] = t;
		i = p;
		p = (i-1)/2;
	}
}
void print(int a[])
{
	int i;
	for(i=0; i<=heapsize; i++)
		printf("%d  ", a[i]);
	printf("\n");
}
void insert(int a[], int n)
{
	heapsize += 1;
	a[heapsize] = -10000;
	increase_key(a, -10000, n);
}
int extract_max(int a[])
{
	if(heapsize < 0)
	{
		printf(" heap underflow \n");
		return (int)NULL;
	}
	int t, maxm = a[0];
	t = a[0];
	a[0] = a[heapsize];
	a[heapsize] = t;
	heapsize -= 1;
	heapify(a, 0);
	return maxm;
}
