#include <stdio.h>
int main()
{
    int arr[100],num,i,n,low,mid,high;
    printf("Enter number of elements:");
    scanf("%d", &n);
    printf("Enter elements : \n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter a number to search : ");
    scanf("%d", &num);
    low = 1;
    high = n;
    while (low <=high)
    {
        mid=(low+high)/2;
        if (arr[mid] < num)
        {
            low= mid+1;
        }
        else if(arr[mid]>num)
        {
            high= mid - 1;
        }
        else if (arr[mid]==num)
        {
            printf("%d is at %dth position in the array!!", num, mid);
            break;
        }
        else
        {
            printf("Element Is Not Found!!");
            break;
        }
    }
    return 0;
}
