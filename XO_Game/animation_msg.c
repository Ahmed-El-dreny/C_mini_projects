#include "animation_msg.h"

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
    printf("|         Welcome to XO Game          |\n");
    Sleep(50);
    printf("|     developed by Ahmed El-dreny     |\n");
    Sleep(100);
    printf("|               HAVE FUN :)           |\n");
    Sleep(50);
    sleep_anima();
    Sleep(1000);
    printf("\033[0m");
}


void win_mas(char *player)
{
    char *str = "Congrats";
    printf("\033[7;1;5;32m");

    for(int counter = 0 ; str[counter] ; counter++)
    {
        printf("%c", str[counter]);
        Sleep(50);
    }
    printf(" %s", player);
    printf("\nit was an awesome game ;)");

    printf("\n\n");

    printf("\033[0m");
}


void lose_mas(char *player)
{
    char *str = "You are loser haha";
    printf("\033[7;1;5;32m");
    printf("%s ", player);
    for(int counter = 0 ; str[counter] ; counter++)
    {
        printf("%c", str[counter]);
        Sleep(50);
    }
    Sleep(500);
    printf("\033[0m");
}

void exit_mas(void)
{
    printf("\033[7;1;5;32m");
    sleep_anima();
    printf("|               Bye Bye               |\n");
    Sleep(50);
    printf("|         Hope you had some fun       |\n");
    Sleep(100);
    printf("|             See you soon :)         |\n");
    Sleep(50);
    sleep_anima();
    Sleep(2000);
    printf("\033[0m");
}
