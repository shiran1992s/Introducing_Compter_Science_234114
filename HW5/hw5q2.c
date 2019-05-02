#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define M 100


/*
 * ----> 2 rows <----
 *
 * The function allocates the necessary memory for the matrix
 *
 * num - the number of rows
 */
int mystrcmp(char* s1, char* s2);
/*
 * ----> 13 rows <----
 *
 * The function allocates the necessary memory for the matrix
 *
 * num - the number of rows
 */
int find_min(char** arr,int n);
/*
 * ----> 9 rows <----
 *
 * The function allocates the necessary memory for the matrix
 *
 * num - the number of rows
 */
char** matrixAllocation(int num);
/*
 * ----> 3 rows <----
 *
 * The function frees the allocated matrix
 *
 * num - the number of rows
 */
void matrixFree(char** matrix,int num);

/*
 * ----> 12 rows <----
 *
 * The function gets the inputs and then find the index with binary search when
 * finish it prints the outcome
 *
 */
int main() {
    int num;
    printf("Please enter the number of words:\n");
    scanf("%d", &num);
    char** arr=matrixAllocation(num);
    if(!arr){
        return -1;
    }

    for(int i=0;i<num;i++){
        scanf("%s",arr[i]);
    }
    int index=find_min(arr,num);
    matrixFree(arr,num);
    printf("%d\n",index);
    return index;
}

int find_min(char** arr,int n){
    if(n<=1 || mystrcmp(arr[0],arr[n-1])<0){ // this means its a sorted array
        return 0;
    }
    // if we are here it means we have at least 2 strings and the minimal one is
    // is not in index 0
    int mid=n/2;
    if(n == 2){
        if(mystrcmp(arr[0],arr[n-1])>0){
            return mid;
        }
    }
    if(mystrcmp(arr[mid],arr[mid+1])>0){ // the string in mid+1 is the first
        return mid+1;
    }else if(mystrcmp(arr[0],arr[mid])>0){ // the first string is between 0,mid
        return find_min(arr,mid);
    }else{
        return find_min(arr+mid+1,n-mid);
    }
    return -1; // we aren't supposed to get here
}

int mystrcmp(char* s1, char* s2){
    for(;*s1 && *s2 && *s1==*s2; s1++,s2++);
    return *s1-*s2;
}

char** matrixAllocation(int num) {
    char **matrix = malloc(sizeof(char*) * num);
    if (matrix == NULL) {
        printf("Dynamic allocation failed");
        return NULL;
    }
    for (int i = 0; i < num; i++) {
        matrix[i] = malloc(sizeof(char) * M);
        if (matrix[i] == NULL) {
            printf("Dynamic allocation failed");
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void matrixFree(char** matrix,int num) {
    for(int i=0;i<num;i++){
        free(matrix[i]);
    }
    free(matrix);
}
