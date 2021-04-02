#include<stdio.h>
#include<stdlib.h>
# define max 50
void activity_selector(int mat[][2], int n);
int main()
{
	int mat[max][2], i, n;
	printf("\n enter the number of activities:   ");
	scanf("%d", &n);
	for(i = 0; i< n; i++)
	{
		printf(" \n enter s[%d]", i);
		scanf("%d", &mat[i][0]);
		printf("\n enter f[%d]:   ", i);
		scanf("%d", &mat[i][1]);
	}
	activity_selector(mat, n);
	return 0;
}
void activity_selector(int mat[][2], int n)
{
	int m, i, k , a[n];
	m = 0;
	a[0] = m;
	k = 1;
	for( i = 1; i<n; i++)
	{
		if(mat[m][1] <= mat[i][0])
		{
			a[k++] = i;
			m = i;
		}
	}
	printf(" \n ACTIVITY IN ORDER:  ");
	for(i = 0; i<k; i++)
		printf(" activity %d  ", a[i]);

}



