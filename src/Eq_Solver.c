#include <stdio.h>
#include<string.h>                 // For concatinating all the eq.
#include <stdlib.h>                // For abs()

int main(void){

   int user_choice;
   char final_equation[50] = " ";

   printf(" Hi, EQ_Solver is here to assits you.\n");

   Sleep(500);
   printf("\nDecide which equations to solve :\n1) Point - slope form: \n2) Double - intercept form:\n");

   int x1, y1, x2, y2, x_intercept, y_intercept;
   int A, B;

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

    A = y2 - y1, B = x2 - x1;

    if(A == 0 && B == 0){                        //  St. lines with no equation.
        printf("\nEquation doesnot exist. Both are same point.");         
        return 0;
    }
    else if(A == 0){                             //  Eq of Vertical St line.
        printf("\nEquation of vertical line is as:\n X = %d",x_intercept);
        return 0;
    }
    else if(B == 0){                             // Eq of  Horizental st line.
        printf("\nEquation of horizental line is as:\n Y = %d",y_intercept);     
        return 0;
    }
    else{                                   // Eq of inclined line ( A,B != 0 )
         int HCF = Hcf(abs(A), abs(B));
         A/= HCF, B/= HCF;                 // A,B is deducted by HCF.
         int C = B*y1 - A*x1;              // Constant of the equation.
         
         if (user_choice == 1)             // For Point - Slope form.
            printf("Equation of line passing through A(%d, %d) and B(%d, %d) is:\n",x1,y1,x2,y2);
         else                              // For double - intercept form
            printf("\nEquation of line with x-intercept (%d units) and y-intercept (%d units) is:\n",x_intercept,y_intercept);
   
// For the Co - officient of the A..
    if((A>0) && (A==1) || (A<0) && (A== -1))    strcat(final_equation,"X ");       // Concatinating with the old-string..
    else    sprintf(final_equation + strlen(final_equation),"%dX ", abs(A));     


// For the co-offiecent of B..
    if ((A>0) && (B<0) || (A<0) && (B>0)){         
       if(B== 1 || B== -1) strcat(final_equation,"+ Y ");                         // Conactinating with the old-string..
       else   sprintf(final_equation + strlen(final_equation), "+ %dY ",abs(B));}             
    else{ 
       if(B== 1 || B== -1)  strcat(final_equation, "- Y ");                       // Concatinating within the old-string..
       else  sprintf(final_equation + strlen(final_equation),"- %dY ", abs(B)); }   

// For the sign and value of C..
    if((A>0) && (C>0) || ((A<0) && (C<0)) sprintf(final_equation + strlen(final_equation),"+ %d = 0",abs(C));       // Concatinating within the old-string..
    else if((A>0) && (C<0) || (A<0) && (C>0)) sprintf(final_equation + strlen(final_equation),"- %d = 0",abs(C));  // Concatinating within the old-string..
    else  strcat(final_equation, "= 0");                                                                        // Concatinating within the old-string..
 }
    printf("%s", final_equation);               // The final Concatenated - String..
} 
