#include "Headers/Player.h"
#include "Headers/Bullet.h"
#include "Headers/Enemy.h"
#include "Headers/FasterEnemy.h"
#include "Headers/TankEnemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include <cstdlib>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    bulletsound = new QMediaPlayer();
    audio = new QAudioOutput();
    bulletsound->setAudioOutput(audio);
    bulletsound->setSource(QUrl("qrc:/sounds/external/arrow.mp3"));
    audio->setVolume(0.5);
}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        if (pos().x() > 0) {
            setPos(x()-10,y());
        }
    }
    else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        if (pos().x()+69 < 800) {
            setPos(x()+10,y());
        }
    }
    else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        if (pos().y() > 0) {
            setPos(x(),y()-10);
        }
    }
    else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        if (pos().y()+69 < 800) {
            setPos(x(),y()+10);
        }
    }
    else if (event->key() == Qt::Key_Space) {
        // create a bullet
        Bullet* bullet = new Bullet();
        bullet->setPos(x()+30,y()-50);
        scene()->addItem(bullet);
        // play bullet sound
        if (bulletsound->playbackState() == QMediaPlayer::PlayingState) {
            bulletsound->setPosition(0);
        }
        else if (bulletsound->playbackState() == QMediaPlayer::StoppedState) {
            bulletsound->play();
        }
    }
}

void Player::spawn(){
    // Generate a random number between 0 and 2
    int enemyType = rand() % 3;

    // Create enemy based on the random number
    if (enemyType == 0) {
        // Spawn Enemy
        Enemy* enemy = new Enemy();
        scene()->addItem(enemy);
    } else if (enemyType == 1) {
        // Spawn FasterEnemy
        FasterEnemy* fasterEnemy = new FasterEnemy();
        scene()->addItem(fasterEnemy);
    } else {
        // Spawn TankEnemy
        TankEnemy* tankEnemy = new TankEnemy();
        scene()->addItem(tankEnemy);
    }
}
