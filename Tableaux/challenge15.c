#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int num , num2;
    int *arr;
    int *arr2;
    int *sum;
    int i = 0 , j = 0 ;

    printf("please enter the number of elements of the first array: ");
    scanf("%d",&num);

    printf("\n");

    printf("please enter the number of elements of the second array: ");
    scanf("%d",&num2);

    arr = malloc (num * sizeof(int));
    arr2 = malloc (num2 * sizeof(int));
    sum = malloc ((num + num2) * sizeof(int));

    if ((arr == NULL) || (arr2 == NULL) ||( sum == NULL))
        return 1;
    
    for (int i = 0; i < num; i++)
    {
        printf("Please enter the values for the first array %d: ",i + 1);
        scanf("%d",&arr[i]);
    }

    printf("\n");

    for (int i = 0; i < num2; i++)
    {
        printf("Please enter the values for the second array %d: ",i + 1);
        scanf("%d",&arr2[i]);
    }
    while(i < num)
    {
        sum[i] = arr[i];
        i++;
    }

    while (j < num2)
    {
        sum[i] = arr2[j];
        i++;
        j++;
    }
    j = 0;
    while (j < i)
    {
        printf("%d \n", sum[j]);
        j++;
    } 
    return 0;  
}