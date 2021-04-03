#include<stdio.h>
#include<string.h>

void search (char text[],char pattern[],int d,int q)
{
	int n= strlen(text);
	int m= strlen(pattern);
	int i,j,s,p=0,t=0,h=1;
	for (i=0;i<m-1;i++)
	{
		h=(h*d)%q;
	}
	for (i=0;i<m;i++)
	{
		p=(d*p+pattern[i])%q;
		t=(d*t+text[i])%q;
	}
	for(s=0;s<=n-m;s++)
	{
		if(p==t)
		{
		/*	for(j=0;j<m;j++)
			{
				if(text[s+j]!=pattern[j])
					break;
			}
			if(j==m)
			{*/
				printf("Pattern occur at %d\n",s);
			//}
		}
		if(s<n-m)
		{
			t=(d*(t-text[s]*h)+text[s+m])%q;
			if(t<0)
			{
				t=t+q;
			}
		}
	}
}
int main()
{
	char text[200];
	char pattern[200];
	printf("Enter the Text: ");
	scanf("%s",text);
	printf("Enter the pattern:");
	scanf("%s",pattern);
	int d=256;
	int q=661;
	search(text,pattern,d,q);
}

