#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int num;
    int min;
    int *arr;
    printf("please enter the number of array element: ");
    scanf("%d",&num);

    arr = malloc (num * sizeof(int));
    if (arr == NULL)
        return 1;
    
    for (int i = 0; i < num; i++)
    {
        printf("plese enter the valuev %d: ",i + 1);
        scanf("%d",&arr[i]);
    }
    
    min = arr[0];
    for (int i = 0 ; i < num ; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("the smallest number is: %d",min);
}