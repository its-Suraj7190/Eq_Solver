#include "St_Line_Eq.h"
#include "HCF.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Point_Slope(int x1,int y1,int x2,int y2)
{
    int A = y2 - y1;
    int B = x2 - x1;

    char eq[100] = "";

    if(A == 0 && B == 0)
    {
        printf("\nEquation does not exist.");
        return;
    }

    if(A == 0)
    {
        printf("\nY = %d\n",y1);
        return;
    }

    if(B == 0)
    {
        printf("\nX = %d\n",x1);
        return;
    }

    int hcf = HCF(abs(A),abs(B));

    A /= hcf; B /= hcf;
    int C = B*y1 - A*x1;

    printf("\nEquation passing through the points (%d,%d) and (%d,%d) is : \n",x1,y1,x2,y2);

    if(abs(A)==1)
        strcat(eq,"X ");
    else
        sprintf(eq + strlen(eq), "%dX ",abs(A));

    if((A>0 && B<0) || (A<0 && B>0)){
      if(abs(B)==1)
         strcat(eq,"+ Y ");
      else
         sprintf(eq + strlen(eq),"+ %dY ",abs(B));
    }
    else{
      if(abs(B)==1)
         strcat(eq,"- Y ");
      else
        sprintf(eq + strlen(eq),"- %dY ", abs(B));
    }

    if(C > 0) sprintf(eq + strlen(eq),"+ %d = 0", C);
    else if(C < 0) sprintf(eq + strlen(eq),"- %d = 0",abs(C));
    else strcat(eq,"= 0");

    printf("%s\n",eq);
}

void Double_Intercept(int x_intercept, int y_intercept)
{
   Point_Slope(0,y_intercept,x_intercept,0);
}
