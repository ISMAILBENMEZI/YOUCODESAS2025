#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct 
{
    char name[20];
    char phone[10];
}contact;

int main ()
{
    contact people[MAX];
    int num ;
    int choice;

    char search[50];
    int found = 0;

    char delet[50];
    int found2 = 0;

    do
    {
        printf("\n(1) Add a contact.\n");
        printf("(2) Show all contacts.\n");
        printf("(3) Search for a contact by name.\n");
        printf("(4) Delete contact by name.\n");
        printf("(5) Leave.\n");

        printf("please enter what do you want: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:

            printf("Your Max is %d \n",MAX);
            printf("how many people do you want to admit: ");
            scanf("%d",&num);
            for (int i = 0; i < num; i++)
            {
                printf("name[%d]: ",i + 1);
                scanf("%s[^\n]", people[i].name);

                printf("phone[%d]: ",i + 1);
                scanf("%s[^\n]", people[i].phone);
                printf("\n");
            }
            printf("\n");
            break;
        case 2:
            printf("\n=== List of people ===\n");
            for (int i = 0; i < num; i++)
            {
                printf("\nname[%d]: %s",i + 1,people[i].name);
                printf("\nphone[%d]: %s",i + 1,people[i].phone);
            }
            printf("\n");
            break;
        case 3:

            printf("\nEnter the name of the person you want to search for: ");
            scanf("%s",search);

            for (int i = 0; i < num; i++)
            {
                if (strcmp(people[i].name , search) == 0)
                {
                    printf("\nThe person was found\n");
                    printf("\nname[%d]: %s",i + 1,people[i].name);
                    printf("\nphone[%d]: %s",i + 1,people[i].phone);
                    printf("\n");
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                printf("\n The person does not exist.\n");
            }
            break;
        case 4:

            printf("\nEnter the name of the person you want to search for: ");
            scanf("%s",delet);

            for (int i = 0; i < num; i++)
            {
                if (strcmp(people[i].name , search) == 0)
                {
                    for (int j = i ; j < num - 1; j++)
                        people[j] = people[j + 1];
                    num--;
                    found2 = 1;
                    printf("\n Deleted %s\n",delet);
                }
            }
            printf("\n");
            if (!found)
            {
                printf("\n The person does not exist.\n");
            }

            printf("\n");
            
            break;
        default:
            break;
        }
    } while (choice != 5);
}
