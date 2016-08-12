#include<stdio.h>
#include<stdlib.h>
/* this function returns median of arr1 and arr2.
    assumption in this function: both the arrays are sorted
    and both have n elements.
*/

int getMedian(int arr1[], int arr2[], int n)
{
    int i = 0, j=0, count;
    int m1 = -1, m2 = -1;
    /* since there are 2n elements, median will be average of
        elements at index n-1 and index n in the array obtained
        after merging the arr1 and arr2
    */

    for(count = 0; count<=n; count++)
    {
        /* Below is the handle condition where all the elements
            of arr1 is smaller than first element of arr2
        */
        if(i == n)
        {
            m1 = m2;
            m2 = arr2[0];
            break;
        }
        /* Below is the condition when all the elements of arr2 is smaller
            than the first element of arr1.
        */
        else if(j == n)
        {
            m1 = m2;
            m2 = arr1[0];
            break;
        }
        if(arr1[i] < arr2[j])
        {
            m1 = m2;
            m2 = arr1[i];
            i++;
        }
        else
        {
            m1 = m2;
            m2 = arr2[j];
            j++;
        }
    }
    return (m1+m2)/2;

}
 int main()
 {
     int arr1[] = {1,12,15,26,38};
     int arr2[] = {2,13,17,30,45};

     int n1 = sizeof(arr1)/sizeof(arr1[0]);
     int n2 = sizeof(arr2)/sizeof(arr2[0]);
     if(n1==n2)
        printf("Median is: %d",getMedian(arr1, arr2, n2));
     else
        printf("Don't work for unequal size of array");
     return 0;
 }
