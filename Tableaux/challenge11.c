#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int num;
    int *arr;
    int old_Value;
    int new_Value;

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

    printf("Please enter the number you want to change: ");
    scanf("%d", &old_Value);

    printf("please enetr the new number you want: ");
    scanf("%d", &new_Value);

    for (int i = 0; i < num ; i++)
    {
        if (arr[i] == old_Value)
        {
            arr[i] = new_Value;
        }
        printf("%d\n",arr[i]);
    }
}