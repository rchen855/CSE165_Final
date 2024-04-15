#include "Bullet.h"
#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>

Bullet::Bullet() {
    // creates the bullet
    setRect(0,0,10,50);

    // connect
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    // check for enemy collision
    QList<QGraphicsItem*> collisions = collidingItems();
    for (int i = 0; i < collisions.size(); i++) {
        if (typeid(*(collisions[i])) == typeid(Enemy)) {
            // remove from scene
            scene()->removeItem(collisions[i]);
            scene()->removeItem(this);
            // delete both items
            delete collisions[i];
            delete this;
            return;
        }
    }

    // move bullet up
    int speed = 10;
    setPos(x(),y()-speed);
    if (pos().y() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
