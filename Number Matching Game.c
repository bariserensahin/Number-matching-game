#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void defineArray(int a[4][4])
{

    int numbers[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8};
    int size = 16;
    srand(time(0));

    int i;
    for (i=0; i<size - 1; i++)
    {
        int j = rand()%15;
        int temp=numbers[j];
        numbers[j]=numbers[i];
        numbers[i]=temp;
    }

    int index=0;
    for (i=0; i<4; i++)
    {
        int j;
        for (j=0; j<4; j++)
        {
            a[i][j] = numbers[index++];
        }
    }
}


void display(int a[4][4], int displayed[4][4], int foundNumbers[10])
{
    int i,j;
    printf(" ----------NUMBER MATCHING GAME----------\n");
    printf("         0       1       2       3");
    printf("\n");
    for(i=0;i<4;i++)
    {
        printf("%d ",i);
        for(j=0;j<4;j++)
        {
            if (displayed[i][j])
            {
                if(foundNumbers[a[i][j]])
                {
                    printf("        ");
                }
                else
                {
                    printf("%8d", a[i][j]);
                }
            }
            else
            {
                printf("       X");
            }
        }
        printf("\n");
    }
}


int main()
{

    int a[4][4];
    int displayed[4][4]={0};
    int x1,x2,y1,y2;
    int foundNumbers[10] = {0};
    int numFound = 0;
    int tries = 0;

    defineArray(a);
    display(a, displayed, foundNumbers);

    while (numFound < 8)
    {
        printf("\nEnter x and y coordinates of your first guess (Enter -1 to quit):\n");
        scanf("%d", &x1);

        if (x1 == -1)
        {
            printf("Game Over!\n");

            return 0;
        }
        scanf("%d",&y1);
        displayed[x1][y1] = 1;
        display(a, displayed, foundNumbers);

        printf("Enter x and y coordinates of your second guess (Enter -1 to quit):\n");
        scanf("%d", &x2);

        if (x2 == -1)
        {
            printf("Game Over!\n");

            return 0;
        }
        scanf("%d", &y2);

        if (x1>=0 && x1<4 && y1>= 0 && y1<4 &&
            x2>=0 && x2<4 && y2>= 0 && y2<4)
        {
            displayed[x1][y1] = 1;
            displayed[x2][y2] = 1;

            display(a, displayed, foundNumbers);

            if (a[x1][y1] == a[x2][y2])
            {
                printf("\n -----------CORRECT GUESS!-----------\n");


                if (!foundNumbers[a[x1][y1]])
                {
                    foundNumbers[a[x1][y1]] = 1;
                    numFound++;
                }

                printf("Found Numbers:");
                int i;
                for (i=0; i<10; i++)
                {
                    if (foundNumbers[i])
                    {
                        printf("-%d", i);
                    }
                }
                printf("\n");

                display(a, displayed, foundNumbers);
                printf("\n");

                displayed[x1][y1] = 1;
                displayed[x2][y2] = 1;
            }
            else
            {
                printf("\nPlease try again.\n");
                displayed[x1][y1] = 0;
                displayed[x2][y2] = 0;
            }

            tries++;
        }
        else
        {
            printf("Invalid coordinates, please enter (0-3) for x or y.\n");
        }
    }

    printf("\nCongratulations You Found All numbers ");
    printf("Total number of tries:%d\n", tries);
    printf("----------------------------------------");


    return 0;
}
