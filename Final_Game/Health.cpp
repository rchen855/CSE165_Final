#include "Health.h"
#include "Game.h"
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

void Health::decrease() {
    health--;
    setPlainText("Health: " + QString::number(health));
    if (getHealth() < 0) {
        game->close();
    }
}

int Health::getHealth() {
    return health;
}
