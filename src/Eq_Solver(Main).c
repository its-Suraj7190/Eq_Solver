#include <stdio.h>
#include "St_Line_Eq.h"

int main()
{
    int choice;

    printf("Hi, EQ Solver is here.\n");

    do
    {
        printf("\n1. Point-Slope Form");
        printf("\n2. Double-Intercept Form");
        printf("\nEnter Choice : ");

        scanf("%d",&choice);

    }while(choice != 1 && choice != 2);

    switch(choice)
    {
        case 1:
        {
            int x1, y1, x2, y2;

            printf("\nEnter first point : ");
            scanf("%d%d",&x1,&y1);
            printf("Enter second point : ");
            scanf("%d%d",&x2,&y2);

            Point_Slope(x1,y1,x2,y2);
            break;
        }

        case 2:
        {
            int a,b;

            printf("\nEnter X-intercept : ");
            scanf("%d",&a);
            printf("Enter Y-intercept : ");
            scanf("%d",&b);

            Double_Intercept(a,b);
            break;
        }
    }
    return 0;
}
