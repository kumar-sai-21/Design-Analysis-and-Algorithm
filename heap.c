#include<stdio.h>
void maxheapify(int [] , int , int);
void buildheap(int [] , int);
void heapsort(int [] , int );
int main()
{
    int n,a[50],i;
    printf("enter range : ");
    scanf("%d",&n);
    printf("enter the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    heapsort(a,n);
    printf("sorted array : \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0 ;
}
void maxheapify(int a[] , int n , int i)
{
    int l,r,largest,temp;
    l=(2*i)+1;
    r=(2*i)+2;
    if(l<n && a[l]>=a[i])
    {
        largest=l;
    }
    else
    {
        largest=i;
    }
    if(r<n && a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;

    maxheapify(a,n,largest);
    }
}
void buildheap(int a[] ,int n)
{
    int i;
    for(i=n/2 ;i>=0;i--)
    {
        maxheapify(a,n,i);
    }
}
void heapsort(int a[] ,int n)
{
    int i,temp;
    buildheap(a,n);
    for(i=n-1;i>=0;i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        maxheapify(a,i,0);
    }
}
