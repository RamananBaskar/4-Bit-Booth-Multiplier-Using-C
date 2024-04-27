#include <stdio.h>

int main() {
    int multiplier, Q0, accumulator, multiplicand;
    printf("Enter the first number (0-7, positive or negative): ");
    scanf("%d",&multiplicand);
    printf("Enter the second number (0-7, positive or negative): ");
    scanf("%d",&multiplier);
    Q0 = 0;
    accumulator = 0;
    int temp;
    int count;
    
    if (multiplicand<0){
    count+=1;
    temp = -multiplicand ;
    multiplicand = 0;
    for (int i = 0; i<4; i++){
        if (((temp>>i)&1)==0){
            multiplicand = multiplicand  + (1<<i);
        }
    }
    multiplicand = multiplicand  + 1;
    }
    
    if (multiplier<0){
    count+=1;
    temp = -multiplier ;
    multiplier = 0;
    for (int i = 0; i<4; i++){
        if (((temp>>i)&1)==0){
            multiplier = multiplier  + (1<<i);
        }
    }
    multiplier = multiplier + 1;
    }
    
    int neg = 0;
    for (int i = 0; i<4; i++){
        if (((multiplicand>>i)&1)==0){
            neg = neg + (1<<i);
        }
    }
    neg = neg + 1;
    
    for (int i = 0; i<4; i++){
        if ( (((multiplier&1)==0) && (Q0 == 0)) || (((multiplier&1)==1) && (Q0 == 1)) ){
            
            Q0 = (multiplier&1);
            multiplier = ((accumulator&1)<<3)+(multiplier>>1);
            accumulator  = (((accumulator>>3)&1)<<3)+(accumulator >> 1);
        }
        else if( (((multiplier&1)==0) && (Q0 == 1)) ){
            
            accumulator = accumulator + multiplicand;
            if( ((accumulator>>4)&1) == 1){
            accumulator = accumulator & ~(16);
            }
            Q0 = (multiplier&1);
            multiplier = ((accumulator&1)<<3)+(multiplier>>1);
            accumulator  = (((accumulator>>3)&1)<<3)+(accumulator >> 1);
            
        }
        else if( (((multiplier&1)==1) && (Q0 == 0)) ){
            accumulator = accumulator + neg;
            if( ((accumulator>>4)&1) == 1){
            accumulator = accumulator & ~(16);
            }
            Q0 = (multiplier&1);
            multiplier = ((accumulator&1)<<3)+(multiplier>>1);
            accumulator  = (((accumulator>>3)&1)<<3)+(accumulator >> 1);
    }
    }
    int result = (accumulator<<4)+multiplier;
    if (((accumulator>>3)&1)==1){
    temp = result ;
    result = 0;
    for (int i = 0; i<8; i++){
        if (((temp>>i)&1)==0){
            result = result  + (1<<i);
        }
    }
    result = result  + 1;
    result = -result;
    }
    
    printf("%d",result);
    
}
