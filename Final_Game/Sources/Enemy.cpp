#include "Headers/Enemy.h"
#include "Headers/Player.h"
#include "Headers/Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

extern Game* game;

Enemy::Enemy() {
    health = 1;
    speed = 5;
    int random_number = rand() % 700;
    setPos(random_number,0);
    // connect
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

int Enemy::getHealth() {
    return health;
}

void Enemy::decreaseHealth() {
    health--;
}

void Enemy::setHealth(int h) {
    health = h;
}

