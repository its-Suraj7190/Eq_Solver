#include"HCF.h"
#include<stdio.h>

int HCF(int X, int Y){            
 // For calcluating the HCF of A aand B.
    while(Y){
        int rmdr = X%Y; 
        X = Y;
        Y = rmdr;
    }
 return X;      // Returns the HCF value of A and B.
}
