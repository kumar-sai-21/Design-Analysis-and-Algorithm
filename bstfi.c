//Sai kumar Satapathy
//Sic 190310248
//Roll No 04
//Group C2
//binary search tree
#include<stdio.h>
#include<stdlib.h>

struct binary{
	int info;
	struct binary *left;
	struct binary *right;
};
typedef struct binary node;
node* insert(node*,int);
node* deleteval(node*,int);
void inorder(node*);
int minele(node*);
int search(node*, int);
int main()
{
	int ele,ch;
	node *start=NULL;
	while(1)
	{
		printf("\nMENU\n");
		printf("1.Insert\n2.inorder\n3.search\n4.minele\n5.exit\n6.delete\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter the element in bst\n");
			       scanf("%d",&ele);
			       start= insert(start,ele);
			       break;
			case 2:printf("\nThe element are\n ");
			       inorder(start);
			       break;
			case 5: exit(0);
				break;
			case 4: printf("minimum element %d\n",minele(start));
				break;
			case 3: printf("\nEnter the Element to be Searched");
				scanf("%d",&ele);
				//printf("%d",search(start,ele));
				int p=(search(start,ele));
				if(p==1)
				{
					printf("%d Element found\n",ele);
				}
				else
				{
					printf("%d Element not found\n",ele);
				}
				break;
            case 6: printf("\nEnter the element to be deleted");
                    scanf("%d",&ele);
                    deleteval(start,ele);
                    break;
			default:printf("Invalid Choice\n");
		}
	}
}
node* insert(node *start, int ele)
{
	if (start==NULL)
	{
		start= (node*)malloc(sizeof(node));
		start-> info=ele;
		start-> left= NULL;
		start-> right=NULL;
		return start;
	}
	else
	{
		if(start->info>ele)
		{
			start->left= insert(start-> left,ele);

		}
		else
		{
			 start ->right=insert (start->right,ele);
		}
	}
}
void inorder(node *start)
{
	if(start!=NULL)
	{

		inorder(start->left);
		printf("%d\t",start->info);
		inorder(start->right);
	}
}
int minele(node *start)
{
	if(start== NULL)
	{
		printf("Three is empty\n");
		return 0;
	}
	else if(start->left==NULL)
	{
		return start->info;
	}
	else
	{
		minele(start->left);
	}
}
int search(node *start, int ele)
{
	if(start==NULL)
	{
		return 0;
	}
	else if(start->info== ele)
	{
		return 1;
	}
	else if(start->info <ele)
	{
		return search(start->right,ele);
	}
	else
	{
		return search(start->left,ele);
	}
}
node* deleteval(node *start,int val)
{
	node *tmp;
	if(start==NULL)
	{
		printf("Element Not Found\n");
	}
	if(start->info<val)
	{
		return deleteval(start->right,val);
	}
	else if (start->info>val)
	{
		return deleteval(start->left,val);
	}
	else
        if(start->left==NULL && start->right==NULL)
    {

        free(start);
        return NULL;
    }
    else if (start->left==NULL)
    {
        node* temp= start->right;
        free(start);
        return temp;
    }
    else if (start->right==NULL)
    {
        node* temp=start->left;
        free(start);
        return temp;
    }
    else
    {
        int min=minele(start->right);
        start->info=min;
        start->right=deleteval(start->right,min);
    }
}
