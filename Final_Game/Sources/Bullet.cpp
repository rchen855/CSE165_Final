#include "Headers/Bullet.h"
#include "Headers/RegularEnemy.h"
#include "Headers/FasterEnemy.h"
#include "Headers/TankEnemy.h"
#include "Headers/Game.h"
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

void Bullet::move() {
    // Move the bullet upward
    int speed = 10;
    setPos(x(), y() - speed);

    // Check for collisions with enemies
    QList<QGraphicsItem*> collisions = collidingItems();
    for (int i = 0; i < collisions.size(); i++) {
        if (typeid(*(collisions[i])) == typeid(RegularEnemy)) {
            // Decrement health of collided enemy
            RegularEnemy* enemy = dynamic_cast<RegularEnemy*>(collisions[i]);
            if (enemy) {
                enemy->decreaseHealth();
                if (enemy->getHealth() <= 0) {
                    // Play death sound
                    QMediaPlayer* music = new QMediaPlayer();
                    QAudioOutput* audio = new QAudioOutput();
                    music->setSource(QUrl("qrc:/sounds/external/death.mp3"));
                    music->setAudioOutput(audio);
                    audio->setVolume(0.5);
                    music->play();

                    // Increase the score
                    game->score->increase(1);

                    // Remove enemy from scene and delete it
                    scene()->removeItem(collisions[i]);
                    delete collisions[i];
                }
            }

            // Remove bullet from scene and delete it
            scene()->removeItem(this);
            delete this;
            return;
        }
        else if (typeid(*(collisions[i])) == typeid(FasterEnemy)) {
            FasterEnemy* fasterEnemy = dynamic_cast<FasterEnemy*>(collisions[i]);
            if (fasterEnemy) {
                fasterEnemy->decreaseHealth();
                if (fasterEnemy->getHealth() <= 0) {
                    // Play death sound
                    QMediaPlayer* music = new QMediaPlayer();
                    QAudioOutput* audio = new QAudioOutput();
                    music->setSource(QUrl("qrc:/sounds/external/death.mp3"));
                    music->setAudioOutput(audio);
                    audio->setVolume(0.5);
                    music->play();

                    // Increase the score
                    game->score->increase(3);

                    // Remove enemy from scene and delete it
                    scene()->removeItem(collisions[i]);
                    delete collisions[i];
                }
            }

            // Remove bullet from scene and delete it
            scene()->removeItem(this);
            delete this;
            return;
        }
        else if (typeid(*(collisions[i])) == typeid(TankEnemy)) {
            TankEnemy* tankEnemy = dynamic_cast<TankEnemy*>(collisions[i]);
            if (tankEnemy) {
                tankEnemy->decreaseHealth();
                if (tankEnemy->getHealth() <= 0) {
                    // Play death sound
                    QMediaPlayer* music = new QMediaPlayer();
                    QAudioOutput* audio = new QAudioOutput();
                    music->setSource(QUrl("qrc:/sounds/external/death.mp3"));
                    music->setAudioOutput(audio);
                    audio->setVolume(0.5);
                    music->play();

                    // Increase the score
                    game->score->increase(5);

                    // Remove enemy from scene and delete it
                    scene()->removeItem(collisions[i]);
                    delete collisions[i];
                }
            }

            // Remove bullet from scene and delete it
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    // Remove bullet from scene when it goes out of bounds
    if (pos().y() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}

