#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <QMediaPlayer>
#include <QAudioOutput>

extern Game* game;

Bullet::Bullet() {
    // draw the bullet
    setPixmap(QPixmap(":/images/external/arrow.png"));

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
            // play death sound
            QMediaPlayer* music = new QMediaPlayer();
            QAudioOutput* audio = new QAudioOutput();
            music->setSource(QUrl("qrc:/sounds/external/death.mp3"));
            music->setAudioOutput(audio);
            audio->setVolume(0.5);
            music->play();
            // increase the score
            game->score->increase();
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
