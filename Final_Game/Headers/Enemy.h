#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy();
    int speed;
    int getHealth();
    void decreaseHealth();
    void setHealth(int health);
public slots:
    void move();
private:
    int health;
};

#endif // ENEMY_H
