#include<stdio.h>
int heapsize;
  void Exchange(int a[],int m,int n)
    {
        int t=a[n];
        a[n]=a[m];
        a[m]=t;
    }
void heapify(int a[],int n,int i)
{
    int largest = i;
    int left = i*2+1;int right = i*2+2;
    if(left <= heapsize && a[left]>a[largest])
          largest=left;
    if(right <=heapsize && a[right]>a[largest])
           largest =right;
    if(largest!=i)
    {
        Exchange(a,i,largest);
        heapify(a,n,largest);
        /* code */
    }

}
void heapsort(int a[],int n)
{
    // build heap
    for(int i=n/2;i>=0;i--)
    {
        heapify(a,n,i);
    }
    //delete heap
    for(int i=n-1;i>=0;i--)
    {
        Exchange(a,0,i);
        heapify(a,n,0);
    }
}
int max(int a[])
{
    return a[0];
}
int extractMax(int a[])
{
    int max= a[0];
    Exchange(a,0,heapsize);
    heapsize--;
    heapify(a,heapsize,0);
    return max;
}

void increasekey(int a[],int i,int key)
{
      a[i]=key;
      while(i>=0 && a[i/2]<key)
      {
          Exchange(a,i/2,i);
          i=i/2;
      }
}
void insertKey(int a[],int key)
{
    heapsize++;
    a[heapsize]=key;
    increasekey(a,heapsize,key);
}
void main()
{
    printf("Enter the size of array \n");
        int n;scanf("%d",&n);
        int a[n];
        printf("enter the array elements \n");
        // int a[]={1,5,6,7,8};
        heapsize=n-1;
        for(int i=0;i<n;i++)
        {
           scanf("%d",&a[i]);
        }
        heapsort(a,n);
        printf("\n After sorting \n");
        for(int i=0;i<n;i++)
        {
             printf("%d ",a[i]);
        }
        printf("\n max= %d\n ",max(a));
        int max= extractMax(a);
        //max= extractMax(a);
        //printf("\n extract max %d \n",max);
         for(int i=0;i<=heapsize;i++)
        {
             printf("%d ",a[i]);
        }
        increasekey(a,2,69);
         printf("\nAfter increasing \n");
        for(int i=0;i<=heapsize;i++)
        {
             printf("%d ",a[i]);
        }
        insertKey(a,0);
           printf("\nAfter inserting \n");
        for(int i=0;i<=heapsize;i++)
        {
             printf("%d ",a[i]);
        }



}
