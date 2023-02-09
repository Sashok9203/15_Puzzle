#include <iostream>
#include "Game.h"
#include <conio.h>

int main()
{
    int arrow;
    Game game(4);
    game.shake(50);
    game.printGameTable();
    do
    {
        do
        {
            arrow = (int)_getch();
        } while ((arrow != arrow_down) && (arrow != arrow_left) && (arrow != arrow_right) && (arrow != arrow_up));
        game.playerMove(Arrows(arrow));
        game.printGameTable();
    } while (!game.check());
    std::cout << " Congratulations !!!! You made it in " << game.getSteps() << " steps";
    system("pause>nul");
}


