#ifndef XO_GAME_FUN_H_INCLUDED
#define XO_GAME_FUN_H_INCLUDED

#include "animation_msg.h"

#define NAME_SIZE            11 //max size of player name
#define ROW_SIZE             3  //number of rows in game table
#define COL_SIZE             3  //number of columns in game table
#define ZERO_INIT            0  //start with value 0
#define TOTAL_MOVES          9  //maximum number of moves to end game
#define MIN_WIN_MOVES        5  //minimum number of moves to win
#define ZERO_RET             0  //function return 0
#define NEW_GAME             1  //make loop true

#define HORIZONTAL_WIN_CASE ((game[0][0] == game[0][1] && game[0][0] == game[0][2] && game[0][0] != ' ')\
                           ||(game[1][0] == game[1][1] && game[1][0] == game[1][2] && game[1][0] != ' ')\
                           ||(game[2][0] == game[2][1] && game[2][0] == game[2][2] && game[2][0] != ' '))  //conditions of rows to win

#define VIRTICAL_WIN_CASE   ((game[0][0] == game[1][0] && game[0][0] == game[2][0] && game[0][0] != ' ')\
                           ||(game[0][1] == game[1][1] && game[0][1] == game[2][1] && game[0][1] != ' ')\
                           ||(game[0][2] == game[1][2] && game[0][2] == game[2][2] && game[0][2] != ' '))  //conditions of columns to win

#define DIAGONAL_WIN_CASE   ((game[0][0] == game[1][1] && game[0][0] == game[2][2] && game[0][0] != ' ')\
                           ||(game[2][0] == game[1][1] && game[2][0] == game[0][2] && game[2][0] != ' '))  //conditions of diagonal to win
/**
 * \brief: initialize all game array by ' '
 * \param: no thing
 * \param: no thing
 * \return: no thing
 *
 */

void init(void);

/**
 * \brief: set players data names nad marks X or O
 * \param: no thing
 * \param: no thing
 * \return: no thing
 *
 */

void player_set(void);

/**
 * \brief: take places and call functions to check state of place and player
 * \param: no thing
 * \param: no thing
 * \return: no thing
 *
 */

void input(void);

/**
 * \brief: check state of game because game_state is static global variable user can't edit it
 * \param: no thing
 * \param: no thing
 * \return: no thing
 *
 */

int state(void);

#endif // XO_GAME_FUN_H_INCLUDED
