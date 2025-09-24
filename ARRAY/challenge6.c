#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num;
    int num2;
    int *arr;

    printf("please enter the number of array element: ");
    scanf("%d",&num);

    printf("please enter the multiplication number: ");
    scanf("%d",&num2);

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
        printf("%d * %d =  %d\n",arr[i] , num2, (num2 * arr[i]));
    }
}