#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num;
    int sum = 0;
    int *arr;

    printf("please enter the number of array element: ");
    scanf("%d",&num);

    arr = malloc(num * sizeof(int));
    if (arr == NULL)
        return 1;
    
    for (int i = 0 ; i < num ; i++)
    {
        printf("plese enter the valuev %d: ",i + 1);
        scanf("%d",&arr[i]);
    }

    for (int i = 0 ; i < num ; i++)
    {
        sum += arr[i];
    }
    printf("the sum of the numbers is: %d", sum);
}