#include "sudoku_animations.h"

static void sleep_anima(void)
{
    for(int counter = 39 ; counter > 0 ; counter--)
    {
        printf("-");
        Sleep(50);
    }
    printf("\n");
}

void welcome_mas(void)
{
    printf("\033[7;1;5;32m");
    sleep_anima();
    printf("|       Welcome to Sudoku puzzle      |\n");
    Sleep(50);
    printf("|     developed by Ahmed El-dreny     |\n");
    Sleep(100);
    printf("|              GOOD LUCK :)           |\n");
    Sleep(50);
    sleep_anima();
    Sleep(1000);
    printf("\033[0m");
}

void win_mas(void)
{
    char *str = "Congrats";
    printf("\033[7;1;5;32m");

    for(int counter = 0 ; str[counter] ; counter++)
    {
        printf("%c", str[counter]);
        Sleep(50);
    }
    printf("\nit was an awesome game ;)");

    printf("\033[0m");
}

void lose_mas(void)
{
    char *str = "You give up! haha \nbye bye loser";
    printf("\033[7;1;5;32m");
    for(int counter = 0 ; str[counter] ; counter++)
    {
        printf("%c", str[counter]);
        Sleep(50);
    }
    printf("\033[0m");
}
