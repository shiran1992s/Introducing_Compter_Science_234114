#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

//------------------------------- Constants ----------------------------//
#define BOARD_MAX_SIDE  25

#define MSG_WELCOME_MESSAGE  0
#define MSG_GET_BOARD_ROWS   1
#define MSG_GET_BOARD_COLS   2
#define MSG_GET_COLOR        3
#define MSG_PLAYER_MOVE      4
#define MSG_WINNER           5
#define MSG_GET_COLUMN       6
#define MSG_COLUMN_FULL      7
#define MSG_NO_WINNER        8
#define FIRST_CELL           0
#define SECOND_CELL          1
#define FIRST_COLOR         'R'
#define SECOND_COLOR        'Y'
#define ROWS                 0
#define COLS                 1
#define PLAYER_1             1
#define PLAYER_2             2
#define ARRAY_SIZE           2
#define SMA                 'a'
#define SMZ                 'z'
#define LAA                 'A'
#define LAZ                 'Z'
#define WIN_NUM              4
char const* const game_messages[];
//---------------------------- Predeclarations -------------------------//
/*
 * Outputs game board.
 *
 * board - contains spaces for empty cells, 'Y' or 'R' for
 *         respective player cells.
 * board_side - contains board dimensions {rows, cols}
 */
void print_board(char board[][BOARD_MAX_SIDE], int board_side[]);
/*
 * Outputs winner or tie message.
 *
 * player_id - the id to be output. Pass <0 for tie.
 */
void print_winner(int player_id);
/*
 * ----> 6 rows <----
 *
 * The function opens the game by summoning 2 more functions "Color" and
 * "BoardSize"
 *
 * ColorArray - the array for the colors 'R' and 'Y'.
 *
 * SizeArray - the array for the quantities of rows and colums
 */
int GameOpening (char ColorArray[],int SizeArray[]);
/*
 * ----> 6 rows <----
 *
 * The function gets the first player color and calls the function
 * "CheckingColor"
 *
 * ColorArray - the array for the colors 'R' and 'Y'.
 */
int Color (char ColorArray[]);
/*
 * ----> 11 rows <----
 *
 * The function checks if the color input is valid , if it's a letter
 * different from a 'R' or 'Y' the player is requested to choose a color
 * again. if its not a letter the program stops
 *
 * ColorArray - the array for the colors 'R' and 'Y'.
 */
int CheckingColor (char ColorArray[]);
/*
 * ----> 4 rows <----
 *
 * The function gets the rows and colums quantities by summoning 2
 * more functions "GetCols" and "GetRows"
 *
 * SizeArray - the array for the quantities of rows and colums
 */
int BoardSize (int SizeArray[]);
/*
 * ----> 10 rows <----
 *
 * The function checks if the rows input is valid , if it's a number
 * bigger than 25 or <=0 the player is requested to choose a number
 * again. if its not a number the program stops
 *
 * SizeArray - the array for the quantities of rows and colums
 */
int GetCols (int SizeArray[]);
/*
 * ----> 10 rows <----
 *
 * The function checks if the colums input is valid , if it's a number
 * bigger than 25 or <=0 the player is requested to choose a number
 * again. if its not a number the program stops
 *
 * SizeArray - the array for the quantities of rows and colums
 */
int GetRows (int SizeArray[]);
/*
 * ----> 4 rows <----
 *
 * The function sets all the values of the game board to " " (spaces) in
 * the beginning
 *
 * Board - the char game board .
 *
 * ColorArray - the array for the colors 'R' and 'Y'.
 */
void EmptyBoard(int SizeArray[],char Board[][BOARD_MAX_SIDE]);
/*
 * ----> 11 rows <----
 *
 * The function asks the player to enter a colum in his turn as long as
 * the board is not full . then it summons 2 functions "CheckColResult"
 * and "ActualMove"
 *
 * SizeArray - the array for the quantities of rows and colums
 * c - a pointer with the current player's color
 * Board - the char game board .
 * pl1 - a pointer with the value of the current player
 * p1 - a pointer with the value of the last move's row (in which row a
 * color was insert)
 */
int NextMove(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int *current_row,int *pl1,char *c);
/*
 * ----> 9 rows <----
 *
 * The function checks if the entered colum is valid - if the colum is full
 * the function states that the colum is full and asks for another 1.
 * if the chosen number is just not valid (<=0 or >number of colums) than
 * the function just ask for a new 1. also the function summons the
 * function "CheckingColum".
 *
 * SizeArray - the array for the quantities of rows and colums
 * Board - the char game board .
 * colum - a pointer with the value of the current chosen colum
 * current_row - a pointer with the value of the last move's row (in which row a
 * color was insert)
 */
int CheckColResult(int SizeArray[],char Board[][BOARD_MAX_SIDE],int colum
        ,int *current_row);
/*
 * ----> 5 rows <----
 *
 * The function sets the p1 pointer value (the row indication pointer)
 * to the last move's row (in which row a color was insert)
 *
 * SizeArray - the array for the quantities of rows and colums
 * colum - a pointer with the value of the current chosen colum
 * Board - the char game board .
 * current_row - a pointer with the value of the last move's row (in which row a
 * color was insert)
 */
int CheckingColum(int SizeArray[],char Board[][BOARD_MAX_SIDE],int colum
        ,int *current_row);
/*
 * ----> 7 rows <----
 *
 * The function make the game play - puts the current color in the selected
 * cell , prints the board after the move and checks if there is a winner
 * by summoning "CheckWinner" function . after that the function summons
 * "ChangeColor" and "ChangePlayer" functions.
 *
 * SizeArray - the array for the quantities of rows and colums
 * c - a pointer with the current player's color
 * Board - the char game board .
 * pl1 - a pointer with the value of the current player
 * current_row - a pointer with the value of the last move's row (in which row a
 * color was insert)
 * colum - a pointer with the value of the current chosen colum
 */
int ActualMove(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int colum,int *current_row,int *pl1,char *c);
/*
 * ----> 4 rows <----
 *
 * The function switches the color according to which player turn it is now
 * by changing a char pointer value
 *
 * color - the char pointer.
 *
 */
char* ChangeColor(char *color);
/*
 * ----> 4 rows <----
 *
 * he function switches the number according to which player turn it is now
 * by changing a int pointer value
 *
 * player - the int pointer.
 */
int* ChangePlayer(int *player);
/*
 * ----> 6 rows <----
 *
 * The function checks if the board is full or not , if its full and there
 * isn't any winner it prints the the outcome is a tie.
 *
 * SizeArray - the array for the quantities of rows and colums
 *
 * Board - the char game board .
 */
int CheckBoard(int SizeArray[],char Board[][BOARD_MAX_SIDE]);
/*
 * ----> 5 rows <----
 *
 * The function checks if there is a winner after each turn and prints a
 * a message if there is one.
 *
 * SizeArray - the array for the quantities of rows and colums
 * c - a pointer with the current player's color
 * Board - the char game board .
 * pl1 - a pointer with the value of the current player
 * p1 - a pointer with the value of the last move's row (in which row a
 * color was insert)
 * colum - a pointer with the value of the current chosen colum
 */
int CheckWinner(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int colum,int *current_row,int *pl1,char *c);
/*
 * ----> 9 rows <----
 *
 * The function checks the colum where the last color was entered and check if
 * there are 4 colors together like the last move's color.
 *
 * SizeArray - the array for the quantities of rows and colums
 * c - a pointer with the current player's color
 * Board - the char game board .
 * current_row - a pointer with the value of the last move's row (in which row a
 * color was insert)
 * colum - a pointer with the value of the current chosen colum
 */
int ColStatus(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int colum,char *c);
/*
 * ----> 9 rows <----
 *
 * The function checks the row where the last color was entered and check if
 * there are 4 colors together like the last move's color.
 *
 * SizeArray - the array for the quantities of rows and colums
 * c - a pointer with the current player's color
 * Board - the char game board .
 * current_row - a pointer with the value of the last move's row (in which row a
 * color was insert)
 * colum - a pointer with the value of the current chosen colum
 */
int RowStatus(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int *current_row,char *c);
/*
 * ----> 11 rows <----
 *
 * The function checks the diagonals crossing the cell where the last color
 * was entered and check if there are 4 colors together like the last
 * move's color.
 *
 * SizeArray - the array for the quantities of rows and colums
 * c - a pointer with the current player's color
 * Board - the char game board .
 * current_row - a pointer with the value of the last move's row (in which row a
 * color was insert)
 * colum - a pointer with the value of the current chosen colum
 */
int DiagonalStatus(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int colum,int *current_row,char *c);
/*
 * ----> 7 rows <----
 *
 * The function checks the upper right side of the diagonal crossing the
 * cell where the last color was entered and counts how much colors are the
 * same
 *
 * SizeArray - the array for the quantities of rows and colums
 * c - a pointer with the current player's color
 * Board - the char game board .
 * current_row - a pointer with the value of the last move's row (in which row a
 * color was insert)
 * colum - a pointer with the value of the current chosen colum
 */
int DiagonalUpRight(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int colum,int *current_row,char *c);
/*
 * ----> 7 rows <----
 *
 * The function checks the lower right side of the diagonal crossing the
 * cell where the last color was entered and counts how much colors are the
 * same
 *
 * SizeArray - the array for the quantities of rows and colums
 * c - a pointer with the current player's color
 * Board - the char game board .
 * current_row - a pointer with the value of the last move's row (in which row a
 * color was insert)
 * colum - a pointer with the value of the current chosen colum
 */
int DiagonalDownRight(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int colum,int *current_row,char *c);
/*
 * ----> 7 rows <----
 *
 * The function checks the lower left side of the diagonal crossing the
 * cell where the last color was entered and counts how much colors are the
 * same
 *
 * SizeArray - the array for the quantities of rows and colums
 * c - a pointer with the current player's color
 * Board - the char game board .
 * current_row - a pointer with the value of the last move's row (in which row a
 * color was insert)
 * colum - a pointer with the value of the current chosen colum
 */
int DiagonalDownLeft(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int colum,int *current_row,char *c);
/*
 * ----> 7 rows <----
 *
 * The function checks the upper left side of the diagonal crossing the
 * cell where the last color was entered and counts how much colors are the
 * same
 *
 * SizeArray - the array for the quantities of rows and colums
 * c - a pointer with the current player's color
 * Board - the char game board .
 * current_row - a pointer with the value of the last move's row (in which row a
 * color was insert)
 * colum - a pointer with the value of the current chosen colum
 */
int DiagonalUpLeft(char Board[][BOARD_MAX_SIDE]
        ,int colum,int *current_row,char *c);
//--------------------------- Main Program -----------------------------//
// ----> 13 rows <----
int main() {
    char color[ARRAY_SIZE],currentColor;
    int size[ARRAY_SIZE],currentPlayer=PLAYER_1,row;
    int *curren_row,*player=&currentPlayer;
    if(GameOpening(color,size))
    {
        currentColor=color[FIRST_CELL];
        char *c=&currentColor;
        row=size[ROWS];
        curren_row=&row;
        char GameBoard[size[ROWS]][BOARD_MAX_SIDE];
        EmptyBoard(size,GameBoard);
        if(NextMove(size,GameBoard,curren_row,player,c))
            return 0;
    }
    return 0;
}
//---------------------- Printing Functions ----------------------------//
// Inclusive check in range
#define IS_IN_RANGEI(VAL, MIN, MAX) (((VAL)>=(MIN)) && ((VAL)<=(MAX)))

char const* const game_messages[] = {
        "Welcome to 4-in-a-row game! \n",
        "Please enter number of rows: ",
        "Please enter number of columns: ",
        "Please choose starting color (Y)ellow or (R)ed: ",
        "Your move, player %d. ",
        "Player %d won! \n",
        "Please enter column: ",
        "Column full. ",
        "That's a tie. \n"
};

enum {BOARD_VERT_SEP=(int)'|',
    BOARD_LEFT_ANG=(int)'\\',
    BOARD_RIGHT_ANG=(int)'/',
    BOARD_BOTTOM=(int)'-',
    BOARD_BOTTOM_SEP=(int)'-'};

void print_board(char board[][BOARD_MAX_SIDE], int board_side[])
{
    assert(IS_IN_RANGEI(board_side[0], 0, BOARD_MAX_SIDE)
           && IS_IN_RANGEI(board_side[1], 0, BOARD_MAX_SIDE));

    for (int row=0; row<board_side[0]; ++row)
    {
        printf("\n%c", (char)BOARD_VERT_SEP);
        for (int col = 0; col < board_side[1]; ++col)
            printf("%c%c", board[row][col], (char)BOARD_VERT_SEP);
    }
    printf("\n%c", (char)BOARD_LEFT_ANG);
    for (int ii=0; ii<board_side[1]-1; ++ii)
        printf("%c%c", (char)BOARD_BOTTOM, (char)BOARD_BOTTOM_SEP);
    printf("%c%c\n", (char)BOARD_BOTTOM, (char)BOARD_RIGHT_ANG);
}

void print_winner(int player_id) {
    if (player_id >= 0)
        printf(game_messages[MSG_WINNER], player_id);
    else
        printf(game_messages[MSG_NO_WINNER]);
}

int GameOpening (char ColorArray[],int SizeArray[]) {
    printf(game_messages[MSG_WELCOME_MESSAGE]);
    if((Color(ColorArray))&&(BoardSize(SizeArray)))
        return 1;
    else
        return 0;
}
int Color (char ColorArray[]) {
    printf(game_messages[MSG_GET_COLOR]);
    scanf(" %c" ,&ColorArray[FIRST_CELL]);
    if(CheckingColor(ColorArray))
        return 1;
    else return 0;
}
int CheckingColor (char ColorArray[]) {
    while ((ColorArray[FIRST_CELL] != FIRST_COLOR)
            && (ColorArray[FIRST_CELL] != SECOND_COLOR))
    {
        if(((ColorArray[FIRST_CELL] >= SMA) && (ColorArray[FIRST_CELL] <= SMZ)) ||
           ((ColorArray[FIRST_CELL] >= LAA) && (ColorArray[FIRST_CELL] <= LAZ)))
        {
            printf(game_messages[MSG_GET_COLOR]);
            scanf(" %c" ,&ColorArray[FIRST_CELL]);
        }
        else return 0;
    }
    if(ColorArray[FIRST_CELL] == FIRST_COLOR)
        ColorArray[SECOND_CELL]=SECOND_COLOR;
    else
        ColorArray[SECOND_CELL]=FIRST_COLOR;
    return 1;
}
int BoardSize (int SizeArray[]) {
    if(((GetRows(SizeArray)) && (GetCols(SizeArray))) == 1)
        return 1;
    else return 0;
}
int GetRows (int SizeArray[]) {
    printf(game_messages[MSG_GET_BOARD_ROWS]);
    if((scanf("%d" ,&SizeArray[ROWS])) == 0)
        return 0 ;
    else
    {
        while((SizeArray[ROWS] > BOARD_MAX_SIDE)||
              (SizeArray[ROWS] <= 0))
        {
            printf(game_messages[MSG_GET_BOARD_ROWS]);
            scanf("%d" ,&SizeArray[ROWS]);
        }
    }
    return 1;
}
int GetCols (int SizeArray[]) {
    printf(game_messages[MSG_GET_BOARD_COLS]);
    if((scanf("%d" ,&SizeArray[SECOND_CELL])) == 0)
        return 0;
    else
    {
        while((SizeArray[SECOND_CELL] > BOARD_MAX_SIDE)
              ||(SizeArray[SECOND_CELL] <= 0))
        {
            printf(game_messages[MSG_GET_BOARD_COLS]);
            scanf("%d" ,&SizeArray[SECOND_CELL]);
        }
    }
    return 1;
}
void EmptyBoard(int SizeArray[],char Board[][BOARD_MAX_SIDE]) {
    for(int i=0;i < SizeArray[ROWS];i++)
    {
        for(int j=0;j < SizeArray[COLS];j++)
            Board[i][j]=' ';
    }
    print_board(Board,SizeArray);
}
int CheckBoard(int SizeArray[],char Board[][BOARD_MAX_SIDE]) {
    for(int i=0;i < SizeArray[ROWS];i++)
    {
        for(int j=0;j < SizeArray[COLS];j++)
        {
            if(Board[i][j] == ' ')
                return 1;
        }
    }
    printf(game_messages[MSG_NO_WINNER]);
    return 0;
}
int CheckWinner(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int colum,int *current_row,int *pl1,char *c) {
    if((ColStatus(SizeArray,Board,colum,c))||
       (RowStatus(SizeArray,Board,current_row,c))||
       (DiagonalStatus(SizeArray,Board,colum,current_row,c)))
    {
        print_winner(*pl1);
        return 1;
    }
    return 0;
}
int NextMove(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int *current_row,int *pl1,char *c) {
    int columChosen;
    while((CheckBoard(SizeArray,Board)) != 0)
    {
        printf(game_messages[MSG_PLAYER_MOVE],*pl1);
        printf(game_messages[MSG_GET_COLUMN]);
        if(scanf("%d" ,&columChosen) <= 0)
            return 0;
        while((CheckColResult(SizeArray,Board,columChosen,current_row)) != 1)
        {
            scanf("%d" ,&columChosen);
        }
        if(ActualMove(SizeArray,Board,columChosen,current_row,pl1,c))
            return 1;
    }
    return 1;
}
int ActualMove(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int colum,int *current_row,int *pl1,char *c) {
    Board[*current_row][colum-1]=*c;
    print_board(Board,SizeArray);
    if(CheckWinner(SizeArray,Board,colum,current_row,pl1,c))
        return 1;
    *pl1=*ChangePlayer(pl1);
    *c=*ChangeColor(c);
    return 0;
}
int* ChangePlayer(int *player) {
    if (*player == PLAYER_1)
        *player=PLAYER_2;
    else
        *player=PLAYER_1;
    return player;
}
char* ChangeColor(char *color) {
    if (*color == FIRST_COLOR)
        *color=SECOND_COLOR;
    else
        *color=FIRST_COLOR;
    return color;
}
int CheckingColum(int SizeArray[],char Board[][BOARD_MAX_SIDE],int colum
        ,int *current_row) {
    for(int row=(SizeArray[ROWS]-1);row >= 0;row--)
        if(Board[row][colum-1] == ' ')
        {
            *current_row=row;
            return 0;
        }
    return 0;
}
int CheckColResult(int SizeArray[],char Board[][BOARD_MAX_SIDE],int colum
        ,int *current_row) {
    if(colum > SizeArray[COLS] || colum<=0)
    {
        printf(game_messages[MSG_GET_COLUMN]);
        return 0;
    }
    if(Board[0][colum-1] != ' ')
    {
        printf(game_messages[MSG_COLUMN_FULL]);
        printf(game_messages[MSG_GET_COLUMN]);
        return 0;
    }
    CheckingColum(SizeArray,Board,colum,current_row);
    return 1;
}
int ColStatus(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int colum,char *c) {
    int counter=0;
    for(int row=0;row < SizeArray[ROWS];row++)
    {
        if(Board[row][colum-1] == (*c))
        {
            counter+=1;
            if(counter >= WIN_NUM)
                return 1;
        }
        else
            counter=0;
    }
    return 0;
}
int RowStatus(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int *current_row,char *c) {
    int counter=0;
    for(int col=0;col < SizeArray[COLS];col++)
    {
        if(Board[*current_row][col] == *c)
        {
            counter+=1;
            if(counter >= WIN_NUM)
                return 1;
        }
        else
            counter=0;
    }
    return 0;
}
int DiagonalStatus(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int colum,int *current_row,char *c) {
    int counter = 1;
    counter+=DiagonalUpRight(SizeArray,Board,colum,current_row,c);
    counter+=DiagonalDownLeft(SizeArray,Board,colum,current_row,c);
    if (counter >= WIN_NUM)
        return 1;
    counter=1;
    counter+=DiagonalUpLeft(Board,colum,current_row,c);
    counter+=DiagonalDownRight(SizeArray,Board,colum,current_row,c);
    if(counter >= WIN_NUM)
        return 1;
    return 0;
}
int DiagonalDownLeft(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int colum,int *current_row,char *c) {
    int counter=0;
    for(int row=*current_row+1,col=colum-1;row < SizeArray[ROWS]
                                  && col > 0;row++,col--)
    {
        if(Board[row][col-1] == *c)
            counter+=1;
        else
            return counter;
    }
    return counter;
}
int DiagonalUpRight(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int colum,int *current_row,char *c) {
    int counter=0;
    for(int row=*current_row-1,col=colum-1;row > 0 && col < SizeArray[COLS];
        row--,col++)
    {
        if(Board[row][col+1] == *c)
            counter+=1;
        else
            return counter;
    }
    return counter;
}
int DiagonalUpLeft(char Board[][BOARD_MAX_SIDE]
        ,int colum,int *current_row,char *c) {
    int counter=0;
    for(int row=*current_row-1,col=colum-1;row > 0
                                  &&col>0;row--,col--)
    {
        if(Board[row][col-1] == *c)
            counter+=1;
        else
            return counter;
    }
    return counter;
}
int DiagonalDownRight(int SizeArray[],char Board[][BOARD_MAX_SIDE]
        ,int colum,int *current_row,char *c) {
    int counter=0;
    for(int row=*current_row+1,col=colum-1;row < SizeArray[ROWS]
                                  && col < SizeArray[COLS];row++,col++)
    {
        if(Board[row][col+1] == *c)
            counter+=1;
        else
            return counter;
    }
    return counter;
}
