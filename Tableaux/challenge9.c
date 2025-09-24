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
    
    int i = 0;
    while ( i < num)
    {
        printf("plese enter the valuev %d: ",i + 1);
        scanf("%d",&arr[i]);
        i++;
    }
    int j = 0;
    while(j < num / 2)
    {
        int temp = arr[j];
        arr[j] = arr[i - 1 - j];
        arr[i - 1 - j] = temp;
        j++;
    }
    j = 0;
    while(j < num)
    {
        printf("%d \n", arr[j]);
        j++;
    }
}