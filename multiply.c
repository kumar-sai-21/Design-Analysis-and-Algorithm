/*
   WAP to perform matric chain multiplication
   Sai Kumar Satapathy
   Roll No 4
   SIC 190310248

*/

#include<stdio.h>
int s[20][20];
int m[20][20];
int i,j;
void matrix(int p[],int n)
{
	//s[n][n];
	//m[n][n];
	int k,l,q;
	for(i=0;i<n;i++)
	{
		m[i][j]=0;
	}
	for (l=2;l<=n;l++)
	{
		for(i=1;i<n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=999999;
			for(k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
				//printf("%d",m[i][n-1]);
			}
		}
	//	printf("%d",m[i][n-1]);
	}
	printf("%d ", m[i][n-1]);
}
void print_paren(int i,int j)
{
	if(i==j)
	{
		printf("A%d",i);
	}
	else
	{
		printf("(");
		print_paren(i,s[i][j]);
		print_paren(s[i][j]+1,j);
		printf(")");
	}
}
int main()
{
	int n;
	printf("Enter the size:");
	scanf("%d",&n);
	int a[n];
	printf("Enter the dimension :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nThe No of Multiplication are:");
	matrix(a,n);
	printf("\nThe Required parenthesis are:\n");
	print_paren(i, j);
	printf("\n");
}

