#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printAfterShift (char c,int shift,int diff);

int main() {
    int shift,diff=0;
    char c;
    printf("Please enter shift number:\n");
    scanf("%d",&shift);
    printf("Please enter text to encrypt:\n");
    while ( scanf("%c",&c) != EOF ){
        printAfterShift(c,shift,diff);
    }
    return 0;
}
// the function gets the inputs and prints the correct char after the right shift
// the function makes the shifts using ASCII calculations in the correct way according to the input.
void printAfterShift (char c,int shift,int diff){
    if (c >= 'a' && c <= 'z'){
        if ('z' - c < shift){
            diff= ('z' - c);
            shift -= diff;
            printf("%c",('a'+shift-1));
        }else{
          printf("%c",c+shift);
        }
    }else if (c >= 'A' && c <= 'Z'){
        if ('Z' - c < shift){
            diff= ('Z' - c);
            shift -= diff;
            printf("%c",('A'+shift-1));
        }else{
           printf("%c",c+shift);
        }
    }else{
     printf("%c",c);
    }
}
