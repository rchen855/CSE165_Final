#include "Bullet.h"
#include <QTimer>

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
    // move bullet up
    int speed = 10;
    setPos(x(),y()-speed);
}
