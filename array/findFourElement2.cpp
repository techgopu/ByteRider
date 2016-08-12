// A better solution O(n^3)

void quickSort(int*, int, int);
void findFourElements2(int arr[],int n, int x)
{
    quickSort(arr,0,n-1);
}
// Function related to quick sort
void exchange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitions(int arr[],int si, int ei)
{
    int x = arr[ei];
    int i = si-1;
    for(int j = si; j<=ei-1; j++)
    {
        if(arr[j]<=x)
        {
            i++;
            exchange(&arr[i],&arr[j]);
        }
    }
    exchange(&arr[i+1],&arr[ei]);
    return (i+1);
}
void quickSort(int arr, int si, int ei)
{
    int pi;
    if(si<ei)
    {
        pi = partitions(arr,si,ei);
        quickSort(arr,si,pi-1);
        quickSort(arr,pi+1,ei);
    }
}
