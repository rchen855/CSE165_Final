#include "Headers/RegularEnemy.h"
#include <QTimer>
#include "Headers/Enemy.h"
#include "Headers/Player.h"
#include "Headers/Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

extern Game* game;

RegularEnemy::RegularEnemy(): Enemy() {
    speed = 4;
    setPixmap(QPixmap(":/images/external/enemy.png"));
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void RegularEnemy::move() {
    // move enemy down
    setPos(x(),y()+speed);
    if (pos().y() > 800) {
        scene()->removeItem(this);
        delete this;
        game->health->decrease();
        return;
    }
    QList<QGraphicsItem*> collisions = collidingItems();
    for (int i = 0; i < collisions.size(); i++) {
        if (typeid(*(collisions[i])) == typeid(Player)) {
            // increate the score
            game->health->decrease();
            // remove from scene
            scene()->removeItem(this);
            // delete both items
            delete this;
            return;
        }
    }
}
