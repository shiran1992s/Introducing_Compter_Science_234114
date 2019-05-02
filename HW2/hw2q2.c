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
#define AMOUNT_OF_INPUTS 3
#define ARRAY_SIZE 26
#define LIMIT_FOR_POWERED 1000000000

// function asking for 3 numbers
void printThreeDigitsOpenMessage();
// function for printing all the results
void printResults(int avg,int rootOfMinNum,int avgPowTwoRootOfMinNum);
//function asking for a sequence of chars
void printCharactersOpenMessage();
//function for printing the number of times each letter appeared
void printDataPerGivenCharAsInput(char ch,int numberOfTimesAppeared);
/*function for printing the number of times a char different from a
 letter appeared*/
void printNumberOfOtherCharsAppeared(int numberOfOtherCharsAppeared);
//function for calculating the average of the numbers
int average(int num[AMOUNT_OF_INPUTS]);
//function for finding the minimum number between two numbers
int min(int num1, int num2);
//function that gives the absolute value of a number
int absolute(int num);
//function for finding the root of a number
int root(int num);
//function for calculating a number powered by another number
long long power(int base, int exp);
/*function for checking how much time each letter appeared and how much
 other chars appeared*/
void characterAnalysis();


/*-------------------------------------------------------------------------
  The main program. (the program gets 3 numbers and returns their average,
  the root of the Absolute minimum number and average power by the Absolute
  value of the minimum number)
 ------------------------------------------------------------------------*/
int main()
{
    int minimum,num[AMOUNT_OF_INPUTS]={0};
    long long int powered;
    printThreeDigitsOpenMessage();
    for(int i=0; i < AMOUNT_OF_INPUTS; i++){
        if(scanf("%d", &num[i]) != 1){
            return -1;
        }
    }
    minimum=min(num[0],num[1]);
    minimum=min(minimum,num[2]);
    minimum=absolute(minimum); //finding the min number and making it positive
    powered = power(average(num),absolute(minimum));
    printResults(average(num),root(minimum),(int)powered);
    characterAnalysis();
    return 0;
}

void printThreeDigitsOpenMessage() {
    printf("Please enter three integers:\n");
}

void printResults(int avg, int rootOfMinNum, int avgPowTwoRootOfMinNum){
    printf("%d %d %d\n", avg, rootOfMinNum,avgPowTwoRootOfMinNum);
}


void printCharactersOpenMessage(){
    printf("Please enter your character set:\n");
}

void printDataPerGivenCharAsInput(char ch, int numberOfTimesAppeared){
    printf(
            "letter %c appeared %d time in the given set of characters\n",
            ch, numberOfTimesAppeared
    );
}
void printNumberOfOtherCharsAppeared(int numberOfOtherCharsAppeared){
    printf(
            "number of other characters in the given set was: %d\n",
            numberOfOtherCharsAppeared
    );
}

int average(int num[AMOUNT_OF_INPUTS]) {
    int  sum=0;
    for(int i=0;i<AMOUNT_OF_INPUTS;i++){
        sum+=num[i];
    }
    return sum/AMOUNT_OF_INPUTS;
}

int min(int num1, int num2) {
    return num1 < num2 ? num1 : num2;
}

int absolute(int num) {
    return num < 0 ? -num : num;
}

int root(int num) {
    if(num < 0) {
        return -1;
    }
    for(int i=0; i*i <= num; i++){
        if(num == i*i)
            return i;
    }
    return -1;
}

long long power(int base, int exp) {
    long long powered=1;
    if(base < 0){
        return -1;
    }
    if(exp < 0){
        return -1;
    }
    for(int i=0; i < exp; i++){
        powered *= base;
    }
    if(powered > LIMIT_FOR_POWERED){
        return -1;
    }
    return powered;
}

void characterAnalysis() {
    char ch='0';
    int total_counter=0,hist_counter[ARRAY_SIZE]={0},ch_hist_values[ARRAY_SIZE];
    for(int i=0;i<ARRAY_SIZE;i++){
        ch_hist_values[i]='a'+i;
    }
    printCharactersOpenMessage();
    while(scanf("%c",&ch) !=  EOF)//*getting input as long its not EOF
    {
        if(ch!='\n' && ch!='\r'){// if its not \n or \r i count it as required
            total_counter++;
        }
        for(int i=0; i<ARRAY_SIZE; i++){
            if(ch == ch_hist_values[i])
                hist_counter[i]++;
        }
    }
    for(int i=0; i<ARRAY_SIZE; i++){ //prints abc letters input amount by order
        printDataPerGivenCharAsInput(ch_hist_values[i],hist_counter[i]);
        total_counter -= hist_counter[i]; // re counting minus the small abc chars
    }
    printNumberOfOtherCharsAppeared(total_counter);
}





