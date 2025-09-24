#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num;
    int *arr;
    int to_Find;
    printf("please enter the number of array element: ");
    scanf("%d",&num);

    arr = malloc (num * sizeof(int));
    if (arr == NULL)
        return 1;
    
    for (int i = 0; i < num ; i++)
    {
        printf("plese enter the valuev %d: ",i + 1);
        scanf("%d",&arr[i]);
    }

    printf("Please enter the number you are looking for: ");
    scanf("%d", &to_Find);

    int i = 0;
    while ( arr[i] != '\0')
    {
        if (arr[i] == to_Find)
        {
            printf("the number is found at index: %d",i);
            return 0;
        }
        i++;
    }

    if (arr[i] == '\0')
        printf("the number is not found");
    return 0;
}