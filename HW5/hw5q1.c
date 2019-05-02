#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DIM 2

/*
 * ----> 14 rows <----
 *
 * The function sorts the intervals with merge sort
 *
 * arr - the matrix
 * n - the number of rows
 */
void sort_intervals(int** arr, int n);
/*
 * ----> 14 rows <----
 *
 * The function merges 2 matrixs into a new sorted one
 *
 * a - the first original matrix
 * a_size - the number of rows in a matrix
 * b - the second original matrix
 * b_size - the number of rows in b matrix
 * c - the new sorted matrix
 */
void merge(int** a,int a_size,int** b,int b_size,int** c);

/*
 * ----> 8 rows <----
 *
 * The continue of the merge function
 *
 * a - the first original matrix
 * ia - the index of row of a , where we stopped at the merge function
 * b - the second original matrix
 * ib - the index of row of b , where we stopped at the merge function
 * c - the new sorted matrix
 * ic - the index of row of c , where we stopped at the merge function
 */
void merge_part2(int** a,int* ia, int** b,
                 int* ib,int** c,int* ic);

/*
 * ----> 6 rows <----
 *
 * The continue of the merge function
 *
 * a - the first original matrix
 * ia - the index of row of a , where we stopped at the merge function
 * a_size - the number of rows in a matrix
 * b - the second original matrix
 * ib - the index of row of b , where we stopped at the merge function
 * b_size - the number of rows in b matrix
 * c - the new sorted matrix
 * ic - the index of row of c , where we stopped at the merge function
 */
void merge_part3(int** a,int a_size,int* ia, int** b,
                 int* ib,int b_size,int** c,int* ic);

/*
 * ----> 3 rows <----
 *
 * The function copies the data from source matrix to the destination matrix
 *
 * dest - the destination matrix
 * src - the source matrix
 * n - the number of rows of each matrix
 */
void memcopy(int** dest,int** src, int n);
/*
 * ----> 11 rows <----
 *
 * The function allocates the necessary memory for the matrix
 *
 * num - the number of rows
 */
int** matrixAllocation(int num);
/*
 * ----> 7 rows <----
 *
 * The function continue to sort the intervals with merge sort
 *
 * arr - the matrix
 * n - the number of rows
 * helper - the matrix who gets the sorted values
 */
void internal_sort_intervals(int** arr, int n,int** helper);
/*
 * ----> 3 rows <----
 *
 * The function prints the matrix after the sort
 *
 * matrix - the matrix
 * size - the number of rows
 */
void print_matrix(int** matrix,int size);

/*
 * ----> 3 rows <----
 *
 * The function frees the allocated matrix
 *
 * num - the number of rows
 */
void matrixFree(int** matrix,int num);

/*
 * ----> 15 rows <----
 *
 * The function gets the inputs and then sort the intervals, when finish it
 * prints the outcome
 *
 */

int main() {
    int num_of_intervals, inputs = 0,result;
    do {
        printf("Please enter the number of intervals:\n");
        scanf("%d", &num_of_intervals);
    } while (num_of_intervals <= 0);
    int **matrix = matrixAllocation(num_of_intervals);
    if (matrix == NULL) {
        return -1;
    }
    do {
        result=scanf("%d%d",&matrix[inputs][0],&matrix[inputs][1]);
        if(result != EOF){
            inputs++;
        }
    }while (result != EOF && inputs < num_of_intervals);
    sort_intervals(matrix,inputs);
    print_matrix(matrix,inputs);
    matrixFree(matrix,num_of_intervals);
    return 0;
    }

void merge(int** a,int a_size, int** b,int b_size,int** c){
    int index_a=0,index_b=0,index_c=0;
    int* ia=&index_a,*ib=&index_b,*ic=&index_c;
    for(;*ia < a_size && *ib < b_size;(*ic)++){
        if(a[*ia][0] < b[*ib][0]){
            c[*ic][0]=a[*ia][0];
            c[*ic][1]=a[*ia][1];
            (*ia)++;
        }else if(a[*ia][0] > b[*ib][0]){
            c[*ic][0]=b[*ib][0];
            c[*ic][1]=b[*ib][1];
            (*ib)++;
        }else{
           merge_part2(a,ia,b,ib,c,ic);
        }
    }
    merge_part3(a,a_size,ia,b,ib,b_size,c,ic);
}

void merge_part2(int** a,int* ia, int** b,
                 int* ib,int** c,int* ic){

            if(a[*ia][1] < b[*ib][1]){
                c[*ic][0]=a[*ia][0];
                c[*ic][1]=a[*ia][1];
                (*ia)++;
            }else{
                c[*ic][0]=b[*ib][0];
                c[*ic][1]=b[*ib][1];
                (*ib)++;
            }

}

void merge_part3(int** a,int a_size,int* ia, int** b,
                 int* ib,int b_size,int** c,int* ic){

    for(;*ia < a_size;(*ia)++){
        c[*ic][0]=a[*ia][0];
        c[(*ic)++][1]=a[*ia][1];
    }
    for(;*ib < b_size;(*ib)++){
        c[*ic][0]=b[*ib][0];
        c[(*ic)++][1]=b[*ib][1];
    }
}

void sort_intervals(int** arr, int n){

    int** temp_array=malloc(sizeof(int*)*n);
    if(temp_array == NULL){
        printf("Dynamic allocation failed");
        return;
    }
    for(int i=0;i < n;i++){
        temp_array[i]=malloc(sizeof(int)*DIM);
        if(temp_array[i] == NULL){
            printf("Dynamic allocation failed");
            free(temp_array);
            return;
        }
    }
    internal_sort_intervals(arr,n,temp_array);
    for(int i=0;i < n;i++){
        free(temp_array[i]);
    }
    free(temp_array);
}


void internal_sort_intervals(int** arr, int n,int** helper){
    int left=n/2,right=n-left;
    if(n < 2){
        return;
    }
    internal_sort_intervals(arr,left,helper);
    internal_sort_intervals(arr+left,right,helper);
    merge(arr,left,arr+left,right,helper);
    memcopy(arr,helper,n);
}


void memcopy(int** dest,int** src, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < DIM; j++) {
            dest[i][j] = src[i][j];
        }
    }
}
int** matrixAllocation(int num) {
    int **matrix = malloc(sizeof(int *) * num);
    if (matrix == NULL) {
        printf("Dynamic allocation failed");
        return NULL;
    }
    for (int i = 0; i < num; i++) {
        matrix[i] = malloc(sizeof(int) * DIM);
        if (matrix[i] == NULL) {
            printf("Dynamic allocation failed");
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void print_matrix(int** matrix,int size) {
    for (int i = 0; i < size; i++) {
        printf("%d %d\n",matrix[i][0],matrix[i][1]);
    }
}

void matrixFree(int** matrix,int num) {
    for(int i=0;i<num;i++){
        free(matrix[i]);
    }
    free(matrix);
}
