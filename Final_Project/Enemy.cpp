#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

Enemy::Enemy() {
    // set random position
    int random_number = rand() % 700;
    setPos(random_number,0);

    // creates the bullet
    setRect(0,0,100,100);

    // connect
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    // move bullet up
    int speed = 5;
    setPos(x(),y()+speed);
    if (pos().y() > 800) {
        scene()->removeItem(this);
        delete this;
        qDebug() << "enemy deleted";
    }
}
