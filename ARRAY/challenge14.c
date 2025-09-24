#include <stdio.h>
#include <stdlib.h>
int main ()
{
    int num;
    int *arr;
    int sum;
    float average;

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

    for (int i = 0; i < num ; i++)
    {
        sum += arr[i];
    }
    average = sum / num;
    printf("the average: %.2f",average);
}