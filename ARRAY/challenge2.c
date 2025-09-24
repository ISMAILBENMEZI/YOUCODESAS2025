#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int num;
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
    
    for (int i = 0 ; i < num ; i++)
    {
        printf("value (%d) is: %d \n" ,i + 1,arr[i]);
    }
}