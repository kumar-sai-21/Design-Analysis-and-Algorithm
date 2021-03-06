/* A Naive recursive implementation of LCS problem */
#include<stdio.h>
char X[10];
char Y[10];
int max(int a, int b);

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(  int m, int n )
{
if (m == 0 || n == 0)
	return 0;
if (X[m-1] == Y[n-1])
	return 1 + lcs( m-1, n-1);
else
	return max(lcs(m, n-1), lcs(m-1, n));
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Driver program to test above function */
int main()
{

    printf("Enter 1st sequence:");
    scanf("%s",X);
    printf("Enter 2nd sequence:");
    scanf("%s",Y);
    int m = strlen(X);
    int n = strlen(Y);
    printf("Length of LCS is %d", lcs( m, n ) );
    return 0;
}
