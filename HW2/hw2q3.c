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
#define MAX 25
#define BAD_ROOT (-1)
//prints open message for size
void printOpenMessageForSudokuSize();
//prints open message for solution
void printOpenMessageForSudokuSolution();
//prints valid message
void printValidSolution();
//prints bad message
void printBadSolution();
//function for finding the root of a number
int root(int num);
//function for getting the input of the sudoku matrix
int sudokuInput(int sudoku[][MAX],int size);
//function for checking the correctness of the cols and rows of the matrix
void rowColTest(int sudoku[][MAX],int size);
//function for checking the correctness of the squares of the matrix
void squareTest(int sudoku[][MAX],int size);

/*-------------------------------------------------------------------------
  receives an input of a size, if a positive number that its
  root is a whole number. then receives an input of the matrix with a size of previous input
  checks that each row and colum has different numbers, after check that every square has different numbers.
  if any fail, it prints bad, else it prints valid.
 ------------------------------------------------------------------------*/
int main()
{
    int size=0;
    printOpenMessageForSudokuSize();
    do
        scanf("%d", &size);
    while(root(size) == BAD_ROOT);
    printOpenMessageForSudokuSolution();
    int sudoku[MAX][MAX]={{0}};
    sudokuInput(sudoku,size);
    rowColTest(sudoku,size);
    squareTest(sudoku,root(size));
    printValidSolution();
    return 0;
}
void printOpenMessageForSudokuSize(){
    printf("Please enter the size of your soduko:\n");
}

void printOpenMessageForSudokuSolution(){
    printf("Please enter your solution:\n");
}

void printValidSolution(){
    printf("Valid solution!\n");
}

void printBadSolution(){
    printf("Bad solution!\n");
}

int root(int num) {
    if(num < 0) {
        return BAD_ROOT;
    }
    for(int i=0; i*i <= num; i++){
        if(num == i*i)
            return i;
    }
    return BAD_ROOT;
}

int sudokuInput(int sudoku[][MAX],int size) {
    int num;
    for(int i=0;i < size;i++) {
        for(int j=0;j < size;j++) {
            scanf("%d", &num);
            sudoku[i][j]=num;
        }
    }
    return 1;
}

void rowColTest(int sudoku[][MAX],int size) {
    bool test_arr_row[MAX+1],test_arr_col[MAX+1];
    for(int i=0;i < size;i++){ 
        for(int k=0;k < size;k++){ //before checking row/col filling false values(sort of a histogram)
            test_arr_row[k+1]= false;
            test_arr_col[k+1]= false;
        }
        for(int j=0;j < size;j++){
            if(test_arr_row[sudoku[i][j]]||test_arr_col[sudoku[j][i]]){//if index is true its a fail,number already in
                printBadSolution();
                exit(1);
            } else { //the row/col index was tested, marks it for next test
                test_arr_row[sudoku[i][j]]=true;
                test_arr_col[sudoku[j][i]]=true;
            }
        }
    }
}

void squareTest(int sudoku[][MAX],int size) {
    bool test_arr[MAX+1];
    int current_row,current_col;
    for(int k=0;k < size;k++)
    {
        current_row=k*size; //jumps to next beggining of row in square
        for(int l=0;l < size;l++)
        {
            current_col=l*size; //jumps to next  beggining of col in square
            for(int m=0;m < MAX+1;m++){ //fills test array false values (sort of a histogram)
                test_arr[m]=false;
            }
            for(int i=current_row;i < size+current_row;i++){
                for(int j=current_col;j < size+current_col;j++){
                    if(test_arr[sudoku[i][j]]){ //if this index is true its a fail,because number already in
                        printBadSolution();
                        exit(1);
                    } else{ //this index was checked, switch it on
                        test_arr[sudoku[i][j]]=true;
                    }
                }
            }
        }
    }
}









