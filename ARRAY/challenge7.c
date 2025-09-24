#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num;
    int temp;
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

    int i = 0;
    int j;

    while(i < num - 1)
    {
        j = 0;
        while(j < num - 1 - i)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; 
            }
            j++;
        }
        i++;
    }
    for (int i = 0; i < num; i++)
    {
        printf("%d \n",arr[i]);
    }

}