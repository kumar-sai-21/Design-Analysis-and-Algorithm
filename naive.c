// C program for Naive Pattern Searching algorithm
#include <stdio.h>
#include <string.h>
char txt[20];
char pat[20];

void search()
{
	int M = strlen(pat);
	int N = strlen(txt);

	/* A loop to slide pat[] one by one */
	for (int i = 0; i <= N - M; i++)
	{
		int j;

		/* For current index i, check for pattern match */
		for (j = 0; j < M; j++)
			if (txt[i + j] != pat[j])
				break;
				if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
				printf("Pattern found at index %d \n", i);
	}
}

/* Driver program to test above function */
int main()
{
	printf("Enter the 1st string\n");
	scanf("%s",txt);
	printf("ENter the second string\n" );
	scanf("%s",pat );
	search();
	return 0;
}
