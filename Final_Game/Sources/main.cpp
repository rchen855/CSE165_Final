#include "Headers/Game.h"
#include <QApplication>

Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->displayMenu();
    game->show();

    return a.exec();
}
