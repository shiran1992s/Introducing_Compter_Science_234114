#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ERROR (-1)

int absolute(int num);
void printData(int sum_boys,int sum_girls,int count_boys,int count_girls);

//getting the necessary inputs and making the necessary calculations returning ERROR (-1) in case of bad input
// and 0 otherwise
int main() {
    int height,sum_boys=0,sum_girls=0,count_boys=0,count_girls=0;
    printf("Students, please enter heights!\n");
    while (scanf("%d",&height)!=EOF){
        if (height == 0){
            printf("Error! Invalid height 0!\n");
            return ERROR;
        }else if (height>0){
            sum_girls += height;
            count_girls++;
        }else {
            sum_boys += absolute(height);
            count_boys++;
        }
    }
    printData(sum_boys,sum_girls,count_boys,count_girls);
    return 0;
}
// the function returns the absolute value of an int input
int absolute(int num){
    return (num < 0) ? -num : num ;
}
// the function prints the Data of the girls and the boys after all the calculations
void printData(int sum_boys,int sum_girls,int count_boys,int count_girls){
    if (sum_girls>0){
        printf("Average girls height is: %.2f\n",((double)sum_girls/count_girls));
    }else {
        printf("No girls in class! :(\n");
    }
    if (sum_boys>0){
        printf("Average boys height is: %.2f\n",((double)sum_boys/count_boys));
    }else {
        printf("No boys in class! :(\n");
    }
}