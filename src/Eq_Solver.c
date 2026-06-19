#include"HCF.h"
#include"St_Line_Eq.h"
#include <stdio.h>
#include <stdlib.h>                // For abs()

int main(void){

   int user_choice;
   char final_equation[50] = " ";

   printf(" Hi, EQ_Solver is here to assits you.\n");

   Sleep(500);
   printf("\nDecide which equations to solve :\n1) Point - slope form: \n2) Double - intercept form:\n");

   int x1, y1, x2, y2, x_intercept, y_intercept;
   int a, b;

   do {
      printf("\nEnter you choice: ");                        //  Ask for the user-choice input.. 
      scanf("%d",&user_choice);

    switch(user_choice){                                        

      case 1:                                         //  For the Point - Slope form.
            printf("\nEnter first point (x1, y1): ");
            scanf("%d %d", &x1, &y1);
            printf("Enter second point (x2, y2): ");
            scanf("%d %d", &x2, &y2);
            break;

      case 2:                                    //  For the Double - Intercept form.
            printf("\nEnter X-intercept(a): ");
            scanf("%d",&x_intercept);
            printf("Enter Y-intercept(b): ");
            scanf("%d",&y_intercept);
            x1 = 0,  y1 = y_intercept,           // Expressing Y-intercept as in (x1,y1).  
            x2 = x_intercept, y2 = 0;            // Expressing X-intercept as in (x2,y2).
            break; 
         
      case 3:                                    // For the invalid choice of 1 and 2.
            printf("Invalid choice. Enter a valid choice only (1 and 2).");   
            break;
    } 
} while(!(user_choice < 3));

    a = y2 - y1, b = x2 - x1;
   St_Line_Eq(a, b);
   return 0;
} 
