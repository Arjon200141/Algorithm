#include <stdio.h>
int main()
{
    int num, i, j, temp;
    int ar[100];
    printf("Enter number of elements: ");
    scanf("%d", &num);
    printf("Enter The Elements : \n");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &ar[i]);
    }
    for (i = 1; i < num; i++)
    {
        j = i;
        while (j > 0 && ar[j - 1] > ar[j])
        {
            temp = ar[j];
            ar[j] = ar[j - 1];
            ar[j - 1] = temp;
            j--;
        }
    }
    printf("Sorted List in Ascending Order:\n");
    for (i = 0; i < num; i++)
    {
        printf("%d\n", ar[i]);
    }
    return 0;
}
