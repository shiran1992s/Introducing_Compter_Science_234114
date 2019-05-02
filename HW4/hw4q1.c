#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define M 50

/*
 * ----> 15 rows <----
 *
 * The function creates the integral image from the original one
 *
 * image - the original matrix
 * n - the number of rows
 * m - the number of colums
 * integral_image - the matrix who gets the integral values
 */
void compute_integral_image(int image[][M], int n, int m,
int integral_image[][M]);

/*
 * ----> 2 rows <----
 *
 * The function calculates the sum of the numbers inside the qiven square in the
 * original matrix
 * rect - an array that contains the measures of the square (corners)
 * integral_image - the matrix who contains the integral values
 */
int sum_rect(int integral_image[][M],int rect[4]);

/*
 * ----> 13 rows <----
 *
 * The function creates the average image from the integral one
 *
 * integral_image - the matrix who contains the integral values
 * n - the number of rows
 * m - the number of colums
 * h - the number of rows in the given square
 * w - the number of colums in the given square
 * average - the matrix who gets the average values after calculations
 */
void sliding_average(int integral_image[][M], int n, int m, int h, int w,
int average[][M]);

/*
 * ----> 4 rows <----
 *
 * The function prints the requested outputs
 *
 * average - the matrix who contains the average values after calculations
 * n - the number of rows
 * m - the number of colums
 * integral_image - the matrix who contains the integral values
 */
void show_result(int integral_image[][M], int n, int m, int average[][M]);

/*
 * ----> 6 rows <----
 *
 * A function for printing an input matrix
 *
 * matrix - An input matrix with values
 * n - the number of rows
 * m - the number of colums
 */
void print_result( int n, int m, int matrix[][M]);

/*
 * ----> 14 rows <----
 *
 * The function gets the necessary inputs from the user , then calculates all
 * the requested matrixs and then prints the results.
 */
int main() {
    int num_row,num_col,slide_row,slide_col,image[M][M]={{0}},
        integral_image[M][M]={{0}},average[M][M]={{0}};
    printf("Enter image dimensions:\n");
    scanf("%d%d",&num_row,&num_col);
    printf("Enter image:\n");
    for(int i = 0; i < num_row ; i++) {
        for (int j = 0; j < num_col; j++) {
            scanf("%d", &image[i][j]);
        }
    }
    printf("Enter sliding window dimensions:\n");
    scanf("%d%d",&slide_row,&slide_col);
    compute_integral_image(image,num_row,num_col,integral_image);
    sliding_average(integral_image,num_row,num_col,slide_row,slide_col,average);
    show_result(integral_image,num_row,num_col,average);
    return 0;
}

void compute_integral_image(int image[][M], int n, int m,
                            int integral_image[][M]){
    for(int i = 0; i < n ; i++){
        for (int j = 0; j < m ; j++) {
            if(i == 0 ){
                if ( j == 0){
                    integral_image[i][j]= image[i][j];
                }
                else {
                    integral_image[i][j]= image[i][j] + integral_image[i][j-1];
                }
            }
            if( j == 0){
                if ( i == 0){
                    integral_image[i][j]= image[i][j];
                }
                else {
                    integral_image[i][j]= image[i][j] + integral_image[i-1][j];
                }
            } else{
                integral_image[i][j]= image[i][j] + integral_image[i][j-1] +
                        integral_image[i-1][j] - integral_image[i-1][j-1];
            }
        }
    }
}

int sum_rect(int integral_image[][M],int rect[4]){
    return (integral_image[rect[2]][rect[3]] -
         integral_image[rect[0]-1][rect[3]] - integral_image[rect[2]][rect[1]-1]
    + integral_image[rect[0]-1][rect[1]-1]);
}

void sliding_average(int integral_image[][M], int n, int m, int h, int w,
                     int average[][M]){
    int  diff_row = h/2, diff_col=w/2;
    for(int i=0; i < M ; i++){
        for(int j=0; j < M; j++){
            int rect[]={i-diff_row,j-diff_col,i+diff_row,j+diff_col};
            if(i < diff_row) {
                rect[0] = 0;
            }else if (i+diff_row >= n) {
                rect[2] = n-1;
            }
            if(j < diff_col) {
                rect[1] = 0;
            }else if (j+diff_col >= m) {
                rect[3] = m - 1;
            }
            average[i][j] = round(((double)sum_rect(integral_image,rect)
                                   /(h*w)));
        }
    }
}

void show_result(int integral_image[][M], int n, int m, int average[][M]) {
    printf("Integral image is:\n");
    print_result(n,m,integral_image);
    printf("Smoothed image is:\n");
    print_result(n,m,average);
}

void print_result( int n, int m, int matrix[][M]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) {
                printf("%d\n", matrix[i][j]);
            } else {
                printf("%d ", matrix[i][j]);
            }
        }
    }
}