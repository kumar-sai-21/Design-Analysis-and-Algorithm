#include<stdio.h>
#include<conio.h>
void merge(int arr[], int start , int mid, int end);
void mergesort(int arr[], int start, int end);
void main()
{

    int arr[50],n;
    printf(" enter the no of elements");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {

        scanf("%d",&arr[i]);

    }
    mergesort(arr,0,n-1);
    printf("\n array after sorting");
    for(int i=0;i<n;i++)
    {
        printf("%d   ",arr[i]);
    }
}
void merge(int arr[], int start, int mid,int end)
{
    int i,j,k;
    int n1=mid-start+1;
    int n2=end-mid;
    int L[30], r[30];
    for(i=0;i<n1;i++)
    {
        L[i]=arr[start+i];
    }
    for(j=0;j<n2;j++)
    {
        r[j]=arr[mid+1+j];
    }
    i=0;
    j=0;
    k=start;
    while(i<n1 && j<n2)
    {
        if(L[i]<=r[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        j++;
    }
    while(j<n2)
    {
        arr[k]=r[j];
        j++;
        k++;
        }
}

void mergesort(int arr[], int start, int end)
{
    if(start < end)
    {
        int mid =start+(end-start)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
