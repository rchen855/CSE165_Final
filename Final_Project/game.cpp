#include "game.h"
#include <QApplication>
#include <QGraphicsScene>
#include "Player.h"
#include <QGraphicsView>
#include <QTimer>


Game::Game(QWidget *parent) {

    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,800);

    // visualize game
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setBackgroundBrush(Qt::white);
    setFixedSize(800,800);

    // create Player to put into the scene
    player = new Player();
    player->setRect(0,0,100,100);
    player->setPos(375,600);

    // make item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add the item to the scene
    scene->addItem(player);

    // spawn enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);



    show();
}
