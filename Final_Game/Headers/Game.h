#ifndef GAME_H
#define GAME_H

#include "Headers/Player.h"
#include "Headers/Score.h"
#include "Headers/Health.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QObject>
#include <QOpenGLWidget>
#include <QPushButton>
#include <QTimer>

class Game: public QGraphicsView {
    Q_OBJECT
public:
    Game(QWidget* parent=0);
    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Health* health;
    QTimer* timer;
    void displayMenu();
    void gameOver();
public slots:
    void backToMenu();
    void tutorial();
    void easyGame();
    void medGame();
    void hardGame();
};

#endif // GAME_H
