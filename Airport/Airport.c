#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int day, month, year;

} date;

typedef struct
{
    int idairplane;
    char model[15];
    int capacity;
    char statut[15];
    date Date;

} Airplanes;

typedef struct
{
    int idAirport;
    char name[50];
    Airplanes flotte[100];
    int nbAvions;

} Airport;

int main()
{
    Airport airport[100];
    int choice = 0, choice2 = 0, choice5 = 0;
    int numAirport = 0, numAirplane = 0;
    int AirportEdit = 0, AirplaneEdit = 0;
    int SearchAirport = 0, SearchAirplane = 0;
    int found = 0, find = 0;
    int IsAvailable = 0, maintenance = 0, In_flight = 0;

    printf("\n\033[0;90m=== Airport Management System ===\033[0m\n");

    do
    {
        printf("\n\033[0;90m=== Airport Management ===\033[0m\n");
        printf("\033[0;32m(1) Greate Airport.\n");
        printf("(2) Add Airport.\n");
        printf("(3) Display Airport Information\n");
        printf("(4) Delete a Airport.\n");
        printf("(5) Statistics\n");
        printf("(6) Exist the program\033[0m\n");

        printf("\nplease enter your choice: ");
        scanf("%d", &choice);

        if (choice < 0 || choice > 5)
        {
            printf("\nError: please enter your choice once again: ");
            scanf("%d", &choice);
        }

        switch (choice)
        {

        case 1:

            printf("enter the number of the airports you want: ");
            scanf("%d", &numAirport);

            for (int i = 0; i < numAirport; i++)
            {
                printf("\n\033[0;32m=== Greate Airport (%d) ===\033[0m\n", i + 1);

                printf("Enter the name[%d]: ", i + 1);
                scanf(" %[^\n]", airport[i].name);

                airport[i].idAirport = i + 17 * 790;

                printf("enter the number of the aircraft you want: ");
                scanf("%d", &numAirplane);

                airport[i].nbAvions = numAirplane;

                for (int j = 0; j < numAirplane; j++)
                {
                    printf("\n\033[0;32m=== Great plane (%d) ===\033[0m\n", j + 1);

                    printf("enter the model[%d]: ", j + 1);
                    scanf(" %[^\n]", airport[i].flotte[j].model);

                    printf("\n(1) Available");
                    printf("\n(2) Under maintenance");
                    printf("\n(3) In flight\n");

                    printf("enter the status[%d]: ", j + 1);
                    scanf("%d", &choice5);

                    if ((choice5 != 1) && (choice5 != 2) && (choice5 != 3))
                    {
                        printf("enter the status[%d]: ", j + 1);
                        scanf("%d", &choice5);
                    }

                    if (choice5 == 1)
                    {
                        strcpy(airport[i].flotte[j].statut, "Available");
                        IsAvailable++;
                    }
                    else if (choice5 == 2)
                    {
                        strcpy(airport[i].flotte[j].statut, "Under maintenance");
                        maintenance++;
                    }
                    else if (choice5 == 3)
                    {
                        strcpy(airport[i].flotte[j].statut, "In flight");
                        In_flight++;
                    }
                    printf("enter the capacity[%d]: ", j + 1);
                    scanf("%d", &airport[i].flotte[j].capacity);

                    printf("enter the date (day/month/year)[%d]\n", j + 1);

                    printf("enter the day: ");
                    scanf("%d", &airport[i].flotte[j].Date.day);

                    if (airport[i].flotte[j].Date.day <= 0 || airport[i].flotte[j].Date.day > 31)
                    {
                        printf("error!");
                        printf("enter the day once again: ");
                        scanf("%d", &airport[i].flotte[j].Date.day);
                    }

                    printf("enter the month: ");
                    scanf("%d", &airport[i].flotte[j].Date.month);

                    if (airport[i].flotte[j].Date.month <= 0 || airport[i].flotte[j].Date.month > 12)
                    {
                        printf("error!");
                        printf("enter the month once again: ");
                        scanf("%d", &airport[i].flotte[j].Date.month);
                    }

                    printf("enter the year: ");
                    scanf("%d", &airport[i].flotte[j].Date.year);

                    if (airport[i].flotte[j].Date.year < 2025 || airport[i].flotte[j].Date.year > 2026)
                    {
                        printf("error!");
                        printf("enter the year once again: ");
                        scanf("%d", &airport[i].flotte[j].Date.year);
                    }

                    airport[i].flotte[j].idairplane = i + j + 15 * 790;
                }
            }
            break;
        case 2:

            printf("\n \033[0;32m === Add Airport === \033[0m\n");

            printf("enter the number of the airports you want: ");
            scanf("%d", &AirportEdit);

            for (int i = numAirport; i < (AirportEdit + numAirport); i++)
            {
                printf("\n\033[0;32m=== Add Airport (%d) ===\033[0m\n", i + 1);

                printf("Enter the name[%d]: ", i + 1);
                scanf(" %[^\n]", airport[i].name);

                airport[i].idAirport = 1 + i + 1 + 17 * 790;

                printf("enter the number of the aircraft you want: ");
                scanf("%d", &AirplaneEdit);

                airport[i].nbAvions = (numAirplane + AirplaneEdit);

                for (int j = numAirplane; j < (numAirplane + AirplaneEdit); j++)
                {
                    printf("\n\033[0;32m=== Add plane (%d) ===\033[0m\n", j + 1);

                    printf("enter the model[%d]: ", j + 1);
                    scanf(" %[^\n]", airport[i].flotte[j].model);

                    printf("\n(1) Available");
                    printf("\n(2) Under maintenance");
                    printf("\n(3) In flight\n");

                    printf("enter the status[%d]: ", j + 1);
                    scanf("%d", &choice5);

                    if ((choice5 != 1) && (choice5 != 2) && (choice5 != 3))
                    {
                        printf("enter the status[%d]: ", j + 1);
                        scanf("%d", &choice5);
                    }

                    if (choice5 == 1)
                    {
                        strcpy(airport[i].flotte[j].statut, "Available");
                        IsAvailable++;
                    }
                    else if (choice5 == 2)
                    {
                        strcpy(airport[i].flotte[j].statut, "Under maintenance");
                        maintenance++;
                    }
                    else if (choice5 == 3)
                    {
                        strcpy(airport[i].flotte[j].statut, "In flight");
                        In_flight++;
                    }

                    printf("enter the capacity[%d]: ", j + 1);
                    scanf("%d", &airport[i].flotte[j].capacity);

                    printf("enter the date (day/month/year)[%d]\n", j + 1);

                    printf("enter the day: ");
                    scanf("%d", &airport[i].flotte[j].Date.day);

                    if (airport[i].flotte[j].Date.day <= 0 || airport[i].flotte[j].Date.day > 31)
                    {
                        printf("error!");
                        printf("enter the day once again: ");
                        scanf("%d", &airport[i].flotte[j].Date.day);
                    }

                    printf("enter the month: ");
                    scanf("%d", &airport[i].flotte[j].Date.month);

                    if (airport[i].flotte[j].Date.month <= 0 || airport[i].flotte[j].Date.month > 12)
                    {
                        printf("error!");
                        printf("enter the month once again: ");
                        scanf("%d", &airport[i].flotte[j].Date.month);
                    }

                    printf("enter the year: ");
                    scanf("%d", &airport[i].flotte[j].Date.year);

                    if (airport[i].flotte[j].Date.year < 2025 || airport[i].flotte[j].Date.year > 2026)
                    {
                        printf("error!");
                        printf("enter the year once again: ");
                        scanf("%d", &airport[i].flotte[j].Date.year);
                    }

                    airport[i].flotte[j].idairplane = i + j + 15 * 790;
                }
            }

            numAirport = numAirport + AirportEdit;
            numAirplane = numAirplane + AirplaneEdit;

            break;
        case 3:

            printf("\n\033[0;32m=== Airport Information ===\033[0m\n");

            for (int i = 0; i < numAirport; i++)
            {
                printf("\nthe Airport name: {%s} \n and the id is: {%d}\n", airport[i].name, airport[i].idAirport);
            }

            printf("\n\033[0;32m(1) Access airport information");
            printf("\n(2) Exist the program\033[0m\n");

            printf("\nplease enter your choice: ");
            scanf("%d", &choice2);

            if (choice2 == 2)
                break;
            else
            {
                printf(" \n\n\t     *  *  *  *  *  *  *  *");
                printf("\n\t     *                    *");
                printf("\n\t     *       Welcome      *");
                printf("\n\t     *                    *");
                printf("\n\t     *  *  *  *  *  *  *  *\n");
            }
            printf("\nplease enter the Airport id you want: ");
            scanf("%d", &SearchAirport);

            float count;

            for (int i = 0; i < numAirport; i++)
            {
                if (airport[i].idAirport == SearchAirport)
                {
                    count = ((float)IsAvailable / airport[i].nbAvions) * 100;
                    printf("\n\033[0;32m=== Airport Information ===\033[0m\n");
                    printf(" the Airport name: %s\n", airport[i].name);
                    printf("the Airport id: %d\n", airport[i].idAirport);

                    printf("\n\033[0;32m=== Statistics ===\033[0m\n");

                    printf("the number of aircraft at the airport: %d\n", airport[i].nbAvions);
                    printf("Occupancy coefficient: %.2f%%\n",count);
                    printf("1) Available: %d.\n2) Under maintenance: %d.\n3) In flight: %d.\n", IsAvailable, maintenance, In_flight);

                    int max = 0, min = 0;
                    char nameMax[20], nameMin[20];

                    for (int j = 0; j < airport[i].nbAvions; j++)
                    {
                        if (airport[i].flotte[j].capacity > airport[i].flotte[j + 1].capacity)
                        {
                            max = airport[i].flotte[j].capacity;
                            strcpy( nameMax , airport[i].flotte[j].model);
                        }
                    }

                    for (int j = 0; j < airport[i].nbAvions; j++)
                    {
                        if (airport[i].flotte[j].capacity < airport[i].flotte[j + 1].capacity)
                        {
                            min = airport[i].flotte[j].capacity;
                            strcpy(nameMin , airport[i].flotte[j].model);
                        }
                    }

                    printf("\nAirplane with largest capacity:%s (%d passengers)\n", nameMax, max);
                    printf("Airplane with smallest capacity:%s (%d passengers)\n", nameMin, min);

                    find = i;
                    found = 1;

                    break;
                }
            }

            if (!found)
            {
                printf("\033[0;31m The Airport does not exist.\033[0m\n");
                break;
            }
            else
            {
                do
                {
                    printf("\n\033[0;90m=== Aircratf Management ===\033[0m\n");

                    printf("\033[0;32m(1) Add a plane.\n");
                    printf("(2) Edit a plane.\n");
                    printf("(3) Delete a plane.\n");
                    printf("(4) Show the list of aircraft.\n");
                    printf("(5) Search for a plane.\n");
                    printf("(6) Return to Airport Management System\033[0m\n");

                    printf("\nplease enter your choice: ");
                    scanf("%d", &choice2);

                    if (choice2 < 1 || choice2 > 6)
                    {
                        printf("\nError: please enter your choice once again: ");
                        scanf("%d", &choice2);
                    }

                    switch (choice2)
                    {

                    case 1:

                        found = 0;

                        printf("enter the number of the aircraft you want: ");
                        scanf("%d", &AirplaneEdit);

                        airport[find].nbAvions = (numAirplane + AirplaneEdit);

                        for (int j = numAirplane; j < (numAirplane + AirplaneEdit); j++)
                        {
                            printf("\n\033[0;32m=== Add plane (%d) ===\033[0m\n", j + 1);

                            printf("enter the model[%d]: ", j + 1);
                            scanf(" %[^\n]", airport[find].flotte[j].model);

                            printf("\n(1) Available");
                            printf("\n(2) Under maintenance");
                            printf("\n(3) In flight\n");

                            printf("enter the status[%d]: ", j + 1);
                            scanf("%d", &choice5);

                            if ((choice5 != 1) && (choice5 != 2) && (choice5 != 3))
                            {
                                printf("enter the status[%d]: ", j + 1);
                                scanf("%d", &choice5);
                            }

                            if (choice5 == 1)
                            {
                                strcpy(airport[find].flotte[j].statut, "Available");
                                IsAvailable++;
                            }
                            else if (choice5 == 2)
                            {
                                strcpy(airport[find].flotte[j].statut, "Under maintenance");
                                maintenance++;
                            }
                            else if (choice5 == 3)
                            {
                                strcpy(airport[find].flotte[j].statut, "In flight");
                                In_flight++;
                            }

                            printf("enter the capacity[%d]: ", j + 1);
                            scanf("%d", &airport[find].flotte[j].capacity);

                            printf("enter the date (day/month/year)[%d]\n", j + 1);

                            printf("enter the day: ");
                            scanf("%d", &airport[find].flotte[j].Date.day);

                            if (airport[find].flotte[j].Date.day <= 0 || airport[find].flotte[j].Date.day > 31)
                            {
                                printf("error!");
                                printf("enter the day once again: ");
                                scanf("%d", &airport[find].flotte[j].Date.day);
                            }

                            printf("enter the month: ");
                            scanf("%d", &airport[find].flotte[j].Date.month);

                            if (airport[find].flotte[j].Date.month <= 0 || airport[find].flotte[j].Date.month > 12)
                            {
                                printf("error!");
                                printf("enter the month once again: ");
                                scanf("%d", &airport[find].flotte[j].Date.month);
                            }

                            printf("enter the year: ");
                            scanf("%d", &airport[find].flotte[j].Date.year);

                            if (airport[find].flotte[j].Date.year < 2025 || airport[find].flotte[j].Date.year > 2026)
                            {
                                printf("error!");
                                printf("enter the year once again: ");
                                scanf("%d", &airport[find].flotte[j].Date.year);
                            }

                            airport[find].flotte[j].idairplane = find + 1 + j + 15 * 790;
                        }

                        numAirplane = numAirplane + AirplaneEdit;

                        printf("\n\033[0;32mAircraft information has been added successfully!!\033[0m\n");

                        break;
                    case 2:
                        printf("\n\033[0;32m=== Edit a plane ===\033[0m\n");

                        printf("enter the aircraft id: ");
                        scanf("%d", &SearchAirplane);

                        found = 0;

                        for (int j = 0; j < numAirplane; j++)
                        {
                            if (airport[find].flotte[j].idairplane == SearchAirplane)
                            {
                                printf("\033[0;90m=== edit aircraft information ===\033[0m\n");

                                printf("(1) change the model\n");
                                printf("(2) change the status\n");
                                printf("(3) change the capacity\n");
                                printf("(4) change the date\n");

                                int choice3;

                                printf("please enter your choice: ");
                                scanf("%d", &choice3);

                                switch (choice3)
                                {
                                case 1:

                                    printf("enter the model[%d]: ", j + 1);
                                    scanf(" %[^\n]", airport[find].flotte[j].model);
                                    break;

                                case 2:

                                    printf("enter the status[%d]: ", j + 1);
                                    scanf(" %[^\n]", airport[find].flotte[j].statut);
                                    break;

                                case 3:

                                    printf("enter the capacity[%d]: ", j + 1);
                                    scanf("%d", &airport[find].flotte[j].capacity);
                                    break;

                                case 4:

                                    printf("enter the date (day/month/year)[%d]\n", j + 1);

                                    printf("enter the day: ");
                                    scanf("%d", &airport[find].flotte[j].Date.day);

                                    if (airport[find].flotte[j].Date.day <= 0 || airport[find].flotte[j].Date.day > 31)
                                    {
                                        printf("error!");
                                        printf("enter the day once again: ");
                                        scanf("%d", &airport[find].flotte[j].Date.day);
                                    }

                                    printf("enter the month: ");
                                    scanf("%d", &airport[find].flotte[j].Date.month);

                                    if (airport[find].flotte[j].Date.month <= 0 || airport[find].flotte[j].Date.month > 12)
                                    {
                                        printf("error!");
                                        printf("enter the month once again: ");
                                        scanf("%d", &airport[find].flotte[j].Date.month);
                                    }

                                    printf("enter the year: ");
                                    scanf("%d", &airport[find].flotte[j].Date.year);

                                    if (airport[find].flotte[j].Date.year < 2025 || airport[find].flotte[j].Date.year > 2026)
                                    {
                                        printf("error!");
                                        printf("enter the year once again: ");
                                        scanf("%d", &airport[find].flotte[j].Date.year);
                                    }
                                    break;

                                default:
                                    break;
                                }

                                found = 1;
                                printf("\n\033[0;32mAirplane information has been changed successfully!!\033[0m\n");
                            }
                        }

                        if (!found)
                        {
                            printf("\n\033[0;31mThe plane does not exist.\033[0m\n");
                        }

                        break;

                    case 3:

                        printf("\n\033[0;32m=== Delet a plane ===\033[0m\n");
                        found = 0;

                        printf("enter the aircraft id: ");
                        scanf("%d", &SearchAirplane);

                        for (int i = 0; i < airport[find].nbAvions; i++)
                        {
                            if (airport[find].flotte[i].idairplane == SearchAirplane)
                            {
                                for (int j = i; j < airport[find].nbAvions - 1; j++)
                                    airport[find].flotte[j] = airport[find].flotte[j + 1];

                                numAirplane--;
                                airport[find].nbAvions--;
                                found = 1;

                                printf("\033[0;32mthe aircraft has been deleted.\033[0m\n");
                                break;
                            }
                        }

                        if (!found)
                            printf("\033[0;31mThe plane does not exist.\033[0m\n");

                        break;

                    case 4:

                        if (airport[find].nbAvions == 0)
                        {
                            printf("\n\033[0;31mThere are no planes to display, Please add planes!!\033[0m\n");
                            break;
                        }

                        printf("\n\033[0;32m=== Airport Information ===\033[0m\n");
                        printf("the Airport name: %s\n", airport[find].name);
                        printf("    --> the Airport id: %d\n", airport[find].idAirport);
                        printf("the number of aircraft at the airport: %d\n", airport[find].nbAvions);

                        int choice4 = 0;

                        printf("\n(1) Sort by entry date");
                        printf("\n(2) Sort by capacity");
                        printf("\n(3) Sort by model\n");

                        printf("please enetr your choice: ");
                        scanf("%d", &choice4);

                        printf("\n\033[0;32m=== Airplane Information ===\033[0m\n");
                        switch (choice4)
                        {
                        case 1:

                            for (int i = 0; i < numAirplane - 1; i++)
                            {
                                for (int j = i; j < numAirplane - i - 1; j++)
                                {
                                    if ((airport[find].flotte[j].Date.year > airport[find].flotte[j + 1].Date.year) ||
                                        ((airport[find].flotte[j].Date.year == airport[find].flotte[j + 1].Date.year) &&
                                         (airport[find].flotte[j].Date.month > airport[find].flotte[j + 1].Date.month)) ||
                                        (airport[find].flotte[j].Date.year == airport[find].flotte[j + 1].Date.year &&
                                         airport[find].flotte[j].Date.month == airport[find].flotte[j + 1].Date.month &&
                                         airport[find].flotte[j].Date.day > airport[find].flotte[j + 1].Date.day))
                                    {
                                        Airplanes temp = airport[find].flotte[j];
                                        airport[find].flotte[j] = airport[find].flotte[j + 1];
                                        airport[find].flotte[j + 1] = temp;
                                    }
                                }
                            }

                            break;
                        case 2:

                            for (int i = 0; i < numAirplane - 1; i++)
                            {
                                for (int j = 0; j < numAirplane - i - 1; j++)
                                {
                                    if (airport[find].flotte[j].capacity > airport[find].flotte[j + 1].capacity)
                                    {
                                        Airplanes temp = airport[find].flotte[j];
                                        airport[find].flotte[j] = airport[find].flotte[j + 1];
                                        airport[find].flotte[j + 1] = temp;
                                    }
                                }
                            }

                            break;
                        case 3:
                            for (int i = 0; i < numAirplane - 1; i++)
                            {
                                for (int j = 0; j < numAirplane - i - 1; j++)
                                {
                                    if (strcmp(airport[find].flotte[j].model, airport[find].flotte[j + 1].model) > 0)
                                    {
                                        Airplanes temp = airport[find].flotte[j];
                                        airport[find].flotte[j] = airport[find].flotte[j + 1];
                                        airport[find].flotte[j + 1] = temp;
                                    }
                                }
                            }
                            break;

                        default:
                            break;
                        }

                        for (int j = 0; j < numAirplane; j++)
                        {
                            printf("\n\033[0;33m === THE PLANE[%d] ===\033[0m\n", j + 1);
                            printf("the model[%d]: %s\n", j + 1, airport[find].flotte[j].model);
                            printf("the airplane id[%d]: %d\n", j + 1, airport[find].flotte[j].idairplane);
                            printf("the status[%d]: %s\n", j + 1, airport[find].flotte[j].statut);
                            printf("the capacity[%d]: %d\n", j + 1, airport[find].flotte[j].capacity);
                            printf("the date(day/month/year)[%d]: %d/%d/%d\n", j + 1, airport[find].flotte[j].Date.day,
                                   airport[find].flotte[j].Date.month, airport[find].flotte[j].Date.year);
                            printf("\n");
                        }

                        printf("\n\033[0;32mAirplane information has been shown successfully!!\033[0m\n");

                        break;
                    case 5:

                        found = 0;

                        printf("enter the aircraft id: ");
                        scanf("%d", &SearchAirplane);

                        for (int j = 0; j < numAirplane; j++)
                        {
                            if (airport[find].flotte[j].idairplane == SearchAirplane)
                            {
                                printf("\n\033[0;32m=== Airplane Information ===\033[0m\n");
                                printf("\n\033[0;33m === THE PLANE[%d] ===\033[0m\n", j + 1);
                                printf("the model[%d]: %s\n", j + 1, airport[find].flotte[j].model);
                                printf("the airplane id[%d]: %d\n", j + 1, airport[find].flotte[j].idairplane);
                                printf("the status[%d]: %s\n", j + 1, airport[find].flotte[j].statut);
                                printf("the capacity[%d]: %d\n", j + 1, airport[find].flotte[j].capacity);
                                printf("the date(day/month/year)[%d]: %d/%d/%d\n", j + 1, airport[find].flotte[j].Date.day,
                                       airport[find].flotte[j].Date.month, airport[find].flotte[j].Date.year);
                                printf("\n");
                                printf("\n\033[0;32mAirplane information has been shown successfully!!\033[0m\n");
                                found = 1;
                            }
                        }

                        if (!found)
                            printf("\033[0;31m The plane does not exist.\033[0m\n");

                        break;

                    default:
                        break;
                    }

                } while (choice2 != 6);
                break;
            }
        case 4:

            printf("\n\033[0;32m=== Delet Airport ===\033[0m\n");
            found = 0;

            printf("enter the airport id: ");
            scanf("%d", &SearchAirport);

            for (int i = 0; i < numAirport; i++)
            {
                if (airport[i].idAirport == SearchAirport)
                {
                    for (int j = i; j < numAirport - 1; j++)
                        airport[j] = airport[j + 1];

                    numAirport--;
                    found = 1;

                    printf("\033[0;32mthe airport has been deleted.\033[0m\n");
                    break;
                }
            }

            if (!found)
                printf("\033[0;31m The Airport does not exist.\033[0m\n");

            break;
        default:
            break;
        }

    } while (choice != 5);
}