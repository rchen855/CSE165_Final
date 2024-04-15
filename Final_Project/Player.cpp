#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        if (pos().x() > 0) {
            setPos(x()-10,y());
        }
    }
    else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        if (pos().x()+100 < 800) {
            setPos(x()+10,y());
        }
    }
    else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        if (pos().y() > 0) {
            setPos(x(),y()-10);
        }
    }
    else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        if (pos().y()+100 < 800) {
            setPos(x(),y()+10);
        }
    }
    else if (event->key() == Qt::Key_Space) {
        // create a bullet
        Bullet* bullet = new Bullet();
        bullet->setPos(x()+47.5,y()-50);
        scene()->addItem(bullet);
    }
}

void Player::spawn(){
    // create an enemy
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
};
