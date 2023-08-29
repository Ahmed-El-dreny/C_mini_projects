#include "xo_game_fun.h"

int main()
{
    welcome_mas();
    init();
    player_set();

    while(state())
    {
        input();
    }

    return 0;
}
