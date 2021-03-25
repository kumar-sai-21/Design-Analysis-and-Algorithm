//Sai Kumar Satapathy
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
void inorder(node*);
int minele(node*);
node* search(node*,int);
int maxele(node*);
int main()
{
	int ele,ch;
	node *start=NULL;
	while(1)
	{
		printf("\nMENU\n");
		printf("1.Insert\n2.inorder\n3.exit\n4.minele\n5.search\n6. maxele\n");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		    case 1: printf("Enter the element in bst\n");
                    scanf("%d",&ele);
                    start= insert(start,ele);
                    break;
			case 2: printf("The element are\n ");
                    inorder(start);
                    break;
			case 3: exit(0);
                    break;
			case 4: printf("minimum element %d\n",minele(start));
                    break;
            case 5: printf("\nEnter the element to be searched:");
                    scanf("%d",&ele);
                    //printf("%d\n",search(start,ele));
                    int p=search(start,ele);
                    if(p==ele)
                        {
                            printf("%d successfully found \n",ele);
                        }
                    else
                        {
                            printf("%d not found successfully \n",ele);
                        }

                    break;
            case 6: printf("\nMaximum element %d ",maxele(start));
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
node* search(node* start,int ele)
{
    if (start==NULL)
    {
        return NULL;
    }

    else if(start->info==ele)
    {
        return start->info;
    }
    else if (start->info<ele)
    {
        return search(start-> right,ele);
    }
    else
    {
        return search(start->left,ele);
    }
    //return -1;
}
int maxele(node* start)
{

    if(start==NULL)
    {

        return NULL;
    }
    else if (start->right==NULL)
    {
        return start->info;
    }
    else
        maxele(start->right);
}
