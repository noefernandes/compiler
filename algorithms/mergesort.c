#include <stdio.h>

void MergeSort(int *a,int begin,int end,int *temp);
void MergeArray(int *a,int begin,int mid,int end,int *temp);

int main(int argc, const char * argv[])
{
    int num[] = {2,5,9,3,6,1,0,7,4,8};
    int temp[10]; 
    MergeSort(num,0,9,temp);
    for(int i = 0;i < 10;i++)
    {
        printf("%d ",num[i]);
    }
    return 0;
}

void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    int i = begin,j = mid;
    int m = mid + 1,n = end;
    int k = 0;

    while(i <= j && m <= n)
    {
        if(a[i] <= a[m])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[m++];
        }
    }

    while(i <= j)
    {
        temp[k++] = a[i++];
    }

    while(m <= n)
    {
        temp[k++] = a[m++];
    }

    for(i = 0; i < k; i++)
    {
        a[begin + i] = temp[i];
    }
}

void MergeSort(int *a,int begin,int end,int *temp)
{
    if(begin < end)
    {

        int mid = (begin + end) / 2;
        MergeSort(a,begin,mid,temp);  
        MergeSort(a,mid + 1,end,temp);   
        MergeArray(a,begin,mid,end,temp); 
    }
}