#include <stdio.h>
int main()
{
    int Arr[100],key, i, num, pos,count = 0;
    printf("Enter Number of Elements : ");
    scanf("%d", &num);
    printf("Enter The Elements : \n");
    for (i = 1; i <= num; i++)
    {
        scanf("%d", &Arr[i]);
    }
    printf("Enter a number to search:");
    scanf("%d", &key);
    for (i = 1; i <= num; i++)
    {
        if (Arr[i] == key)
        {
            pos=i;
            count=1;
            break;
        }
    }
    if (count == 1)
    {
        printf("%d is at %dth position in the Array!!\n", key,pos);
    }
    else
    {
        printf("%d isn't found in the Array!!!\n", key);
    }
    return 0;
}
