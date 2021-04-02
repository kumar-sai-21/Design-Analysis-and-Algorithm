//knapsack problem

//sai kumar satapathy

#include<stdio.h>
float prow[20];
float p[20];
void knapsack(int m,int n)
{
	float total_profit=0,x[20];
	int i;
	for (i=0;i<n;i++)
	{
		x[i]=0.0;
	}
	for(i=0;i<n;i++)
	{
		if(prow[i]>m)
		{
			break;
		}
		x[i]=1;
		m=m-prow[i];
		total_profit=total_profit+p[i];
	}
	if(i<n)
	{
		x[i]=(m)/prow[i];
		total_profit=total_profit+(float)x[i]*p[i];
	//printf("the max profit is %f",total_profit);
	}
	printf("the max profit is %f",total_profit);
}
int main()
{
	int weight,n,i,j;
	float ratio[20],temp;
	printf("Enter the capacity of the bag\n");
	scanf("%d",&weight);
	printf("Enter the number of items\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Product %d\n",i+1 );
		printf("Enter the weight of item %d :",i+1);
		scanf("%f",&prow[i]);
		printf("enter the profit in product %d :",i+1);
		scanf("%f",&p[i]);
		ratio[i]=p[i]/prow[i];
		printf("%f\n",ratio[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(ratio[j]<ratio[j+1])
			{
				temp=ratio[j];
				ratio[j]=ratio[j+1];
				ratio[j+1]=temp;

				temp=prow[j];
				prow[j]=prow[j+1];
				prow[j+1]=temp;

				temp =p[j];
	 			p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	knapsack(weight,n);
}
