#ifndef SODUKO_H_INCLUDED
#define SODUKO_H_INCLUDED

#include "soduko_animations.h"

#define ROW                     9
#define COL                     9
#define MAX_NUM_ELEMENT         81               //ROW*COL
#define FIXED_ELEMENTS          23               //fixed elements when game start
#define FIXED_PLACES            (row == 0 && col == 3) || (row == 0 && col == 8) || (row == 1 && col == 1) || (row == 1 && col == 4) || (row == 1 && col == 5)||\
       (row == 2 && col == 3) || (row == 2 && col == 4) || (row == 2 && col == 8) || (row == 3 && col == 2) || (row == 3 && col == 7)||\
       (row == 3 && col == 8) || (row == 4 && col == 2) || (row == 4 && col == 6) || (row == 5 && col == 0) || (row == 5 && col == 1)||\
       (row == 5 && col == 6) || (row == 6 && col == 0) || (row == 6 && col == 4) || (row == 6 && col == 5) || (row == 7 && col == 3)||\
       (row == 7 && col == 4) || (row == 8 && col == 0) || (row == 8 && col == 5)        //fixed places that not empty at game start


/** \brief: init_soduko fun initialize data at beginning of program
 *
 * \param: takes no thing
 * \return: return no thing
 *
 */
void init_soduko(void);

/** \brief: print_soduko print soduko table
 *
 * \param: takes no thing
 * \return: return no thing
 *
 */
void print_soduko(void);

/** \brief: set_num fun to add new number
 *
 * \param: takes number to add as char
 * \param: takes row number
 * \param: takes column number
 * \return: 1 if add done successfully, 0 if not
 *
 */
char set_num(char num, int row, int col);

/** \brief: edit_num fun to edit number
 *
 * \param: takes number as char to edit
 * \param: takes row number
 * \param: takes column number
 * \return: 1 if modification done successfully, 0 if not
 *
 */
char edit_num(char num, int row, int col);

/** \brief: is_finsh fun check if the user fill all empty boxes or no
 *
 * \param: takes no thing
 * \return: return 1 if the user still has an empty boxes, else return 0
 *
 */
char is_finsh(void);

#endif // SODUKO_H_INCLUDED
