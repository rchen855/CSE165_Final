#include "Headers/TankEnemy.h"
#include "Headers/Game.h"
#include <QTimer>

extern Game* game;

TankEnemy::TankEnemy() : Enemy() {
    // Initialize health to 2 (same as before)
    Enemy::setHealth(3);

    // Initialize speed to 3 (slower than before)
    speed = 2;

    // Set position and pixmap
    setPixmap(QPixmap(":/images/external/tankenemy.png"));
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void TankEnemy::move() {
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
