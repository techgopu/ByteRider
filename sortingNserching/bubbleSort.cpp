// program to sort a list of integer using bubble sort
#include<iostream>
#define SIZE 20
using namespace std;

class Sorting
{
private:
    int state[SIZE];
public:
    Sorting(arr[])
    {
        *state = *arr;
    }
    void swapIntegers(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void bubbleSort(int arr[], int n)
    {
        for(int i=0; i<n-1;i++)
        {
            for(int j=0; j<n-i+1; j++)  // last element goes to its position
            {
                if(arr[j]>arr[j+1])
                {
                    swapIntegers(&arr[j],&arr[j+1]);
                }
            }
        }
    }
    void insertionSort(int arr[], int n)
    {
        int key,j;
            for(int i = 0; i<n; i++)
            {
                key = arr[i];
                j = i-1;
                while(j>=0 && arr[j]>key)
                {
                    arr[j] = arr[j+1];
                    j = j-1;
                }
                arr[j+1] = key;
            }
    }

    void selectionSort(int arr[], int n)
    {
        int minIndex;
        for(int i = 0; i<n-1; i++)
        {
            minIndex=i;
            for(int j = i+1; j<n; j++)
            {
                if(arr[j]<arr[minIndex])
                    minIndex=j;
            }
            swapIntegers(&arr[i], &arr[minIndex]);
        }
    }

    void modifiedBubbleSort(int arr[], int n)
    {
        bool swapped;
        for(int i=0; i<n-1; i++)
        {
            swapped = true;
            for(int j=0; j<n-i-1; j++)
            {
                if(arr[j+1]<arr[j])
                {
                    swapped = false;
                    swapIntegers(&arr[j], &arr[j+1]);
                }
            }
            if(swapped)
                break;
        }
    }
    void printArray(int arr[], int n)
    {
        for(int i=0; i<n; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};
int main()
{
    Sorting s;
    s.bubbleSort()
    return 0;
}







