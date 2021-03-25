// C program for Naive Pattern Searching algorithm
#include <stdio.h>
#include <string.h>
char text[20];
char pattern[20];

void search()
{
	int M = strlen(pattern);
	int N = strlen(text);

	/* A loop to slide pat[] one by one */
	for (int i = 0; i <= N - M; i++)
	{
		int j;

		/* For current index i, check for pattern match */
		for (j = 0; j < M; j++)
			if (text[i + j] != pattern[j])
				break;
				if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
				printf("Pattern found at index %d \n", i);
	}
}

/* Driver program to test above function */
int main()
{
	printf("Enter the text string\n");
	scanf("%s",text);
	printf("ENter the pattern\n" );
	scanf("%s",pattern );
	search();
	return 0;
}
