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
    if (getHealth() < 0) {
        for (int i = 0; i < game->scene->items().size(); i++) {
            game->scene->items()[i]->setEnabled(false);
            game->scene->items()[i]->setOpacity(0);
        }
        game->gameOver();
        return;
    }
    setPlainText("Health: " + QString::number(health));
}

int Health::getHealth() {
    return health;
}
