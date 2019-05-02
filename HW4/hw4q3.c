/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/


/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main()
{
    int question;
    char answer[] = {
		's', 'a', 'b', 'a', 'l', 'a'
	};

	scanf("%d",&question);

    printf("The answer to question %d is %c\n", question, answer[question]);

    return 0;
}
