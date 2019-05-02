#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MINUS false
#define PLUS  true


/*
 * ----> 15 rows <----
 *
 * The function finds the longest requested serie with backtracking
 *
 * arr - the array with the number inputs
 * n - the length of the array
 */
int max_crazy(int* arr,int n);
/*
 * ----> 8 rows <----
 *
 * The function is an auxilary for the main max_crazy function
 *
 * arr - the array with the number inputs
 * n - the length of the array
 * index - the current relevant index
 * last - boolean flag for the last sign (MINUS/PLUS)
 * used - the boolean array(contains true where there is a number who is part
 * of the requested serie)
 * total_size - the original length of the array
 */
int max_crazy_aux(int* arr,int n,int index,bool last,bool* used,int total_size);
/*
 * ----> 4 rows <----
 *
 * The function returns false if the 2 inputs has same sign(negetive/positive)
 * and true otherwise
 *
 * diff - the current difference between the 2 numbers in the array
 * last - boolean flag for the last sign (MINUS/PLUS)
 */
bool check(int diff,bool last);
/*
 * ----> 2 rows <----
 *
 * The function resets the boolean array to false values
 *
 * arr - the boolean array
 * n - the length of the array
 */
void used_reset(bool* arr,int n);
/*
 * ----> 5 rows <----
 *
 * The function counts the true values in the array
 *
 * arr - the boolean array
 * n - the length of the array
 */
int countTrue(bool* arr,int n);
/*
 * ----> 13 rows <----
 *
 * The function gets the inputs and then find the requested serie when
 * finish it prints the outcome
 *
 */

int main() {
    int num;
    printf("Please enter the length of the sequence:\n");
    do{
        scanf("%d",&num);
    }while(num<=0);
    int* arr=malloc(sizeof(int)*num);
    if(!arr){
        return -1;
    }
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",max_crazy(arr,num));
    free(arr);
    return 0;
}

int max_crazy(int* arr,int n){
    bool* used=malloc(sizeof(bool)*n);
    bool last;
    if(n<2){ // array with less than 2 numbers cannot have requested serie
        return 0;
    }
    used_reset(used,n);
    int diff,index=1,counter_true=0,counter_max_true=0;
    for(int i=0;i<n-1;i++){
        diff=arr[i+1]-arr[i];
        last=(diff<0)?MINUS:PLUS;
        used[i]=true;
        counter_true= max_crazy_aux(arr+i+1,n-i-1,index+i,last,used,n)+1;
        counter_max_true=((counter_max_true<counter_true)?
                          counter_true:counter_max_true);
        used_reset(used,n);
    }
    free(used);
    return counter_max_true;
}
int max_crazy_aux(int* arr,int n,int index,bool last,bool* used,int total_size) {
    if (n <= 1 || index > n-1) {
        return countTrue(used,total_size);
    }
    int diff=arr[index]-arr[0];
    if(check(diff,last)){
        last=(diff<0)?MINUS:PLUS;
        used[total_size-n]=true;
        return max_crazy_aux(arr+index,n-index,1,last,used,total_size);
    }
    return max_crazy_aux(arr,n,index+1,last,used,total_size);
}

bool check(int diff,bool last){
    if((diff<0 && last == MINUS) ||
       (diff>0 && last == PLUS)){
        return false;
    }
    return true;
}

int countTrue(bool* arr,int n){
    int counter=0;
    for(int i=0;i<n;i++){
       if(arr[i]==true){
           counter++;
       }
    }
    return counter;
}
void used_reset(bool* arr,int n){
    for(int i=0;i<n;i++){
        arr[i]=false;
    }
}

