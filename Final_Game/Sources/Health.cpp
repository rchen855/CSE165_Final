#include "Headers/Health.h"
#include "Headers/Game.h"
#include <QFont>

extern Game* game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    // initialize score to 0
    health = 3;

    // draw the score
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

Health::~Health() {
    // Destructor
}

void Health::decrease() {
    health--;
    if (getHealth() == -1) {
        game->gameOver();
        return;
    }
    setPlainText("Health: " + QString::number(health));
}

int Health::getHealth() {
    return health;
}
