#include "xo_game_fun.h"

/***********************************Global Static Varibles********************************************/

static int game_num = 1, p1_result = 0, p2_result = 0, total_moves = 0, game_state = 1;
static char p1[NAME_SIZE] = {0}, p2[NAME_SIZE] = {0};
static char p1_chos = ' ', p2_chos = ' ';
static char game[ROW_SIZE][COL_SIZE];

/*************************************Static Functions**********************************************/


/**
 * \brief: store sentence, word or letter in array
 * \param: array of characters
 * \param: letters number
 * \return: void
 *
 */

static void string_scan(char *str, int size)
{
    int counter = 0;
    fflush(stdin);
    printf(" Enter player name: ");
    while(str[counter - 1] != '\n' && counter < size)
    {
        scanf("%c", (str + counter) );
        counter++;
    }
    fflush(stdin);
    str[counter-1] = 0;
}

/**
 * \brief: print game details game number, score of each player and players names
 * \param: no thing
 * \param: no thing
 * \return: no thing
 *
 */

static void game_details(void)
{
    printf("\033[7;1;5;32m");
    printf("*---------------------------------------------*\n");
    printf("|                   Round: %d                  |\n", game_num);
    printf("|%-10s: %2d                 %-10s: %2d|\n", p1, p1_result, p2, p2_result);
    printf("*---------------------------------------------*\n");
    printf("\033[0m");
}

/**
 * \brief: print XO table
 * \param: no thing
 * \param: no thing
 * \return: no thing
 *
 */

static void desplay(void)
{
    system("cls");
    game_details();
    printf("\n*-----------*\n");
    for(int row = ZERO_INIT; row < ROW_SIZE; row++)
    {
        printf("|");
        for(int col = ZERO_INIT; col < COL_SIZE; col++)
        {
            printf(" %c", game[row][col]);
            printf(" |");
        }
        printf("\n");
        printf("*-----------*\n");
    }
    printf("\n");
}

/**
 * \brief: edit players names and open same game
 * \param: no thing
 * \param: no ting
 * \return: no thing
 *
 */

static void edit_players_names(void)
{
    init();
    int choice = 0;
    printf("Which player you want to edit his name:\n>> Choose 1,2 or 3\n");
    printf("1- Player1: %s\n", p1);
    printf("2- Player2: %s\n", p2);
    printf("3- both\n");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        string_scan(p1, NAME_SIZE);
        break;

    case 2:
        string_scan(p2, NAME_SIZE);
        break;

    case 3:
        string_scan(p1, NAME_SIZE);
        string_scan(p2, NAME_SIZE);
        break;

    default:
        printf("\033[4;31m");
        printf("INVALID INPUT!!!\nNO change will happen\n");
        printf("\033[0m");
    }
}

/**
 * \brief: ask user if he want to continue in same game, open new game, change names or exit
 * \param: no thing
 * \param: no thing
 * \return: no thing
 *
 */

static void end_game(void)
{
    int choice = 0;
    total_moves = 0;
    system("cls");

    printf(">> Choose 1,2,3 or 4\n");
    printf("1- Play again\n");
    printf("2- New Game\n");
    printf("3- Edit Player Name\n");
    printf("4- Exit\n");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        game_state = NEW_GAME;
        game_num++;
        init();
        break;

    case 2:
        game_state = NEW_GAME;
        player_set();
        init();
        game_num = 1, p1_result = 0, p2_result = 0;
        break;

    case 3:
        game_state = NEW_GAME;
        edit_players_names();

    case 4:
        game_state = ZERO_RET;
        system("cls");
        exit_mas();
        break;

    default:
        printf("\033[4;31m");
        printf("INVALID INPUT!!!\ngame will continue\n");
        Sleep(500);
        printf("\033[0m");
    }
}

/**
 * \brief: check if player win or draw
 * \param: no thing
 * \param: no thing
 * \return: no thing
 *
 */

static void win_check(void)
{
    if(MIN_WIN_MOVES <= total_moves && (HORIZONTAL_WIN_CASE || VIRTICAL_WIN_CASE || DIAGONAL_WIN_CASE))
    {
        if(total_moves & 1)
        {
            p1_result++;
            desplay();
            win_mas(p1);
            lose_mas(p2);
            Sleep(1000);
            end_game();
        }
        else
        {
            p2_result++;
            desplay();
            win_mas(p2);
            lose_mas(p1);
            Sleep(1000);
            end_game();
        }
    }
    else if(TOTAL_MOVES == total_moves)
    {
        desplay();
        printf("\033[1;5;34m");
        printf("\nexciting game it's draw\n");
        Sleep(1000);
        printf("\033[0m");
        end_game();
    }
}

/**
 * \brief: check if place that player select could be edited or no
 * \param: row number that player select
 * \param: column number that player select
 * \param: player mark X or O
 * \return: no thing
 *
 */

static void box_check(int row, int col, char chr)
{
    if(' ' == game[row][col] && col >= 0 && col < 3 && row < 3 && row >= 0)
    {
        game[row][col] = chr;
        total_moves++;
    }
    else
    {
        printf("\033[4;31m");
        printf("you con't edit this box choose another\n");
        Sleep(500);
        printf("\033[0m");
    }
}

/*************************************Functions**********************************************/

/**
 * \brief: set players data names nad marks X or O
 * \param: no thing
 * \param: no thing
 * \return: no thing
 *
 */

void player_set(void)
{
    system("cls");
    printf("Choose player1 X or O: ");
    fflush(stdin);
    scanf("%c", &p1_chos);

    if(p1_chos == 'x' || p1_chos == 'o')
    {
        p1_chos = p1_chos - ('a' - 'A');
    }

    while(p1_chos != 'X' && p1_chos != 'O')
    {
        printf("\033[4;31m");
        printf("\nyou must choose X or O you can't enter without that\n");
        printf("\033[0m");
        printf("Choose player1 X or O: ");
        fflush(stdin);
        scanf("%c", &p1_chos);
        fflush(stdin);

        if(p1_chos == 'x' || p1_chos == 'o')
        {
            p1_chos = p1_chos - ('a' - 'A');
        }
    }

    if(p1_chos == 'X')
    {
        p2_chos = 'O';
    }
    else
    {
        p2_chos = 'X';
    }

    system("cls");

    printf("choose player names must be equal 10 or less\n\n");

    printf("player1:\n");
    string_scan(p1, NAME_SIZE);

    printf("\nplayer2:\n");
    string_scan(p2, NAME_SIZE);
}

/**
 * \brief: initialize all game array by ' '
 * \param: no thing
 * \param: no thing
 * \return: no thing
 *
 */

void init(void)
{
    system("cls");
    for(int row = ZERO_INIT; row < ROW_SIZE; row++)
    {
        for(int col = ZERO_INIT; col < COL_SIZE; col++)
        {
            game[row][col] = ' ';
        }
    }
}

/**
 * \brief: take places and call functions to check state of place and player
 * \param: no thing
 * \param: no thing
 * \return: no thing
 *
 */

void input(void)
{
    int row = -1, col = -1;
    desplay();
    if(total_moves & 1)
    {
        printf("\033[34m");
        printf(">> %s\n", p2);
        printf("Enter row number: ");
        scanf("%d", &row);
        printf("Enter column number: ");
        scanf("%d", &col);
        printf("\033[0m");
        box_check(row - 1, col - 1, p2_chos);
    }
    else
    {
        printf("\033[36m");
        printf(">> %s\n", p1);
        printf("Enter row number: ");
        scanf("%d", &row);
        printf("Enter column number: ");
        scanf("%d", &col);
        printf("\033[0m");
        box_check(row - 1, col - 1, p1_chos);
    }
    win_check();
}

/**
 * \brief: check state of game because game_state is static global variable user can't edit it
 * \param: no thing
 * \param: no thing
 * \return: no thing
 *
 */

int state(void)
{
    return game_state;
}
