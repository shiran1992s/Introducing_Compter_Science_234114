#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE_OF_DICT 19
#define MAX_SIZE_OF_STRING 10


/*
 * ----> 16 rows <----
 *
 * The function prints the requested output according to a given dictionary
 *
 * dic - A given dictionary array
 * num_of_strings - the number of the word inputs
 */

void result(char* dic[],int num_of_strings);

/*
 * ----> 6 rows <----
 *
 * The function returns the ascii sum value of a given string input
 *
 * str - the string input
 */
int wordToAscii(char* str);


/*
 * ----> 14 rows <----
 *
 * The function gets the necessary inputs the then after each string input
 * the function prints all the words in the dictionary with the same ascii
 * value
 *
 */

int main() {
    int num_of_strings;
    char* dictionary[SIZE_OF_DICT]={"AVOCADO","BANNANA","WATER","CAT"
            ,"DOG","HELLO","ISRAEL","ITALY","GARMISH","USA","BRAZIL"
            ,"KING","ABCDy","INT","CHAR","DOUBLE","hardcheese","realize"
            ,"farther"};
    char* opening = "Please enter a non-negative number:";
    do{
        printf("%s\n",opening);
        opening="Please enter a NON-NEGATIVE number:";
        scanf("%d",&num_of_strings);
    }while(num_of_strings < 0);
    if(num_of_strings == 0){
        printf("no strings\n");
    }else{
        printf("Please enter %d strings:\n",num_of_strings);
        result(dictionary,num_of_strings);
    }
    return 0;
}

int wordToAscii(char* str) {
    int sum = 0;
    char *tmp = str;
    while (*tmp != '\0') {
        sum += *tmp;
        tmp++;
    }
    return sum;
}
void result(char* dic[],int num_of_strings){
    int i=0,counter=0;
    char temp[MAX_SIZE_OF_STRING];
    while (i < num_of_strings && scanf("%s",temp) == 1){
        for(int j=0;j < SIZE_OF_DICT;j++){
            if(wordToAscii(temp) == wordToAscii(dic[j])){
                counter++;
            }
        }
        if(counter == 0){
            printf("the string %s has no matches in the dictionary\n",temp);
        }else{
            printf("the string %s has %d matches in the dictionary:\n"
                   ,temp,counter);
            for(int j=0;j < SIZE_OF_DICT;j++){
                if(wordToAscii(temp) == wordToAscii(dic[j])){
                    printf("%s\n",dic[j]);
                }
            }
        }
        i++;
        counter=0;
        printf("\n\n");
    }
}