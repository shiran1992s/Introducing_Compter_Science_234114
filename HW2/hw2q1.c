/*-------------------------------------------------------------------------
  Include files:
-------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*=========================================================================
  Constants and definitions:
=========================================================================*/

/* put your #defines and typedefs here*/


void printGivenParamsToTheOutput(
        char ch, int asciiCode, int asciiCodePowTwo,
        int difference, int unitDigitOfDiff
);
void printResults(int digitsCounter,int lettersCounter,int spacesCounter);
int CountingS(char ch1);
int CountingL(char ch1);
int CountingD(char ch1);

/*-------------------------------------------------------------------------
  scanning a string of characters until ";", and returning analysis of
  each: the char, the ASCII of it, (the ASCII)^2, the ASCII - the previous
  ASCII, the last digit with the sign of the last number.
  in the end it prints statistics of sum of numbers letters and others.
 ------------------------------------------------------------------------*/
int main() {
    char ch;
    int counterDigit=0, counterLetter=0, counterSpace=0, last=0;
    scanf("%c", &ch);
    while(ch != ';'){
        printGivenParamsToTheOutput(ch,ch,ch*ch,ch-last,((ch-last)%10));
        counterDigit += CountingD(ch);
        counterLetter += CountingL(ch);
        counterSpace += CountingS(ch);
        last=ch;
        scanf("%c", &ch);
    }
    printResults(counterDigit, counterLetter, counterSpace);
    return 0;
}
void printGivenParamsToTheOutput(
        char ch, int asciiCode, int asciiCodePowTwo,
        int difference, int unitDigitOfDiff
){
    printf(
            "%c%10d%10d%10d%10d\n", ch, asciiCode,
            asciiCodePowTwo, difference, unitDigitOfDiff
    );
}
void printResults(int digitsCounter,int lettersCounter,int spacesCounter){
    printf("Number of digits received: %d\n",digitsCounter);
    printf("Number of letters received: %d\n",lettersCounter);
    printf("Number of spaces received: %d\n",spacesCounter);
}

//function for counting the number of digit chars
int CountingD(char ch1) {
    return ((ch1 >= '0') && (ch1 <= '9'));
}
//function for counting the number of letter chars
int CountingL(char ch1) {
    return (((ch1 >= 'a') && (ch1 <= 'z')) || ((ch1 >= 'A') && (ch1 <= 'Z')));
}
//function for counting the number of space chars
int CountingS(char ch1) {
    return (ch1 == ' ');
}
