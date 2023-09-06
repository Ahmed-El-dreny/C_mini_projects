#include "sudoku.h"

static char arr[ROW][COL];
static int num_of_digits = MAX_NUM_ELEMENT - FIXED_ELEMENTS;
static char arr2[FIXED_ELEMENTS];

/***************************Static functions**********************************/


/** \brief: check_validity_num fun check if i can add or edit number or not
 *
 * \param: takes number you want to add as char
 * \param: takes row number as int
 * \param: takes col number as int
 * \return: 1 if place entered contains a fixed data
 *          2 if number entered out of range
 *          3 if number exist in the same row once before
 *          4 if number exist in the same column once before
 *
 */

static char check_validity_num(char num, int row, int col)
{
    int counter;

    if(FIXED_PLACES)
    {
        return 1;
    }

    else if(!(row >= 0 && row < 9) || !(col >= 0 && col < 9))
    {
        return 2;
    }

    else if(!(num >= '1' && num <= '9'))
    {
        return 2;
    }

    for(counter = 0; counter < 9; counter++)
    {
        if(arr[row][counter] == num)
        {
            return 3;
        }
        if(arr[counter][col] == num)
        {
            return 4;
        }
    }
    return 0;
}

/***************************functions**********************************/

/** \brief: init_soduko fun initialize data at beginning of program
 *
 * \param: takes no thing
 * \return: return no thing
 *
 */


void init_soduko(void)
{

    int row, col;

    for(row = 0; row < 9; row++)
    {
        for(col = 0; col < 9; col++)
        {
            arr[row][col] = ' ';
        }
    }
    arr[0][3] = '8', arr[0][8] = '3';
    arr[1][1] = '2', arr[1][4] = '1', arr[1][5] = '4';
    arr[2][3] = '3', arr[2][4] = '7', arr[2][8] = '2';
    arr[3][2] = '2', arr[3][7] = '8', arr[3][8] = '6';
    arr[4][2] = '7', arr[4][6] = '9';
    arr[5][0] = '1', arr[5][1] = '5', arr[5][6] = '2';
    arr[6][0] = '2', arr[6][4] = '9', arr[6][5] = '3';
    arr[7][3] = '2', arr[7][4] = '8';
    arr[8][0] = '5', arr[8][5] = '7';
}


/** \brief: print_soduko print soduko table
 *
 * \param: takes no thing
 * \return: return no thing
 *
 */

void print_soduko(void)
{
    printf("\033[32m");

    int col, row;

    printf("*===================================*\n");
    printf("\033[7;1;5;32m");
    printf("|                                   |\n");
    printf("|         Soduko puzzle :)          |\n");
    printf("|                                   |\n");
    printf("\033[0m");
    printf("\033[32m");
    printf("*===================================*\n");

    for(row = 0; row < 9; row++)
    {
        for(col = 0; col < 9; col++)
        {
            printf("|");

            if(FIXED_PLACES)
            {
                printf("\033[7;1;5;32m");

                printf(" %c ",arr[row][col]);

                printf("\033[0m");
            }
            else
            {
                printf("\033[32m");

                printf(" %c ",arr[row][col]);
            }

            printf("\033[32m");

            if(col == 8)
            {
                printf("|");
            }
        }
        if(row != 8)
        {
            printf("\n*-----------------------------------*\n");
        }
    }

    printf("\n*===================================*\n");

    printf("\033[0m");
}

/** \brief: set_num fun to add new number
 *
 * \param: takes number to add as char
 * \param: takes row number
 * \param: takes column number
 * \return: 1 if add done successfully, 0 if not
 *
 */

char set_num(char num, int row, int col)
{
    row--;
    col--;

    printf("\033[4;1;31m");

    if(check_validity_num(num, row, col) == 1)
    {
        printf("\nyou can't change this numbers\nyou can only change numbers that is entered by you or empty boxes");

        printf("\033[0m");

        return 0;
    }

    else if(check_validity_num(num, row, col) == 2)
    {
        printf("OUT OF RANGE !!!\ntry again and make sure that rows, columns and numbers have range from 1 to 9\n");

        printf("\033[0m");

        return 0;
    }

    else if(check_validity_num(num, row, col) == 3)
    {
        printf("There is the same number in the same row\n");

        printf("\033[0m");

        return 0;
    }

    else if(check_validity_num(num, row, col) == 4)
    {
        printf("There is the same number in the same column\n");
        printf("\033[0m");
        return 0;
    }

    else
    {
        printf("\033[0m");

        arr[row][col] = num;
        num_of_digits--;
        return 1;
    }
}


/** \brief: edit_num fun to edit number
 *
 * \param: takes number as char to edit
 * \param: takes row number
 * \param: takes column number
 * \return: 1 if modification done successfully, 0 if not
 *
 */

char edit_num(char num, int row, int col)
{
    row--;
    col--;

    printf("\033[4;1;31m");

    if(check_validity_num(num, row, col) == 1)
    {
        printf("\nyou can't change this numbers\nyou can only change numbers that is entered by you or empty boxes");

        printf("\033[0m");

        return 0;
    }

    else if(check_validity_num(num, row, col) == 2)
    {
        printf("OUT OF RANGE !!!\ntry again with numbers from 1 to 9\n");

        printf("\033[0m");

        return 0;
    }

    else if(check_validity_num(num, row, col) == 3)
    {
        printf("There is the same number in the same row\n");

        printf("\033[0m");

        return 0;
    }

    else if(check_validity_num(num, row, col) == 4)
    {
        printf("There is the same number in the same column\n");

        printf("\033[0m");

        return 0;
    }

    else
    {
        printf("\033[0m");

        arr[row][col] = num;
        return 1;
    }
}


/** \brief: is_finsh fun check if the user fill all empty boxes or no
 *
 * \param: takes no thing
 * \return: return 1 if the user still has an empty boxes, else return 0
 *
 */

char is_finsh(void)
{
    if(num_of_digits)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
