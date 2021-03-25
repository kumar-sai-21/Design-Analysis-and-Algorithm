#include<stdio.h>


    void Exchange(int a[],int m,int n)
    {
        int t=a[n];
        a[n]=a[m];
        a[m]=t;
    }
    int Partisan(int a[],int start,int end)
    {


        int x=a[end];
        int i=start-1,j;
        for(j=start;j<end;j++)
        {
            if(a[j]<=x)
            {
                i++;
                Exchange(a,j,i);
            }
        }
       Exchange(a, i+1,end);
        return i+1;
    }

     void QuickSort(int a[],int start,int end)
     {
         int mid;
         if(start<end)
         {
             mid=Partisan(a,start,end);
             QuickSort(a, start, mid-1);
             QuickSort(a, mid+1, end);
         }
     }
     void main() {

        printf("Enter the size of array \n");
        int n;scanf("%d",&n);
        int a[n];
        printf("enter the array elements \n");
        // int a[]={1,5,6,7,8};
        int start=0,end=n-1;
        for(int i=0;i<n;i++)
        {
           scanf("%d",&a[i]);
        }
        QuickSort(a,start,end);
        for(int i=0;i<n;i++)
        {
             printf("%d ",a[i]);
        }
    }
