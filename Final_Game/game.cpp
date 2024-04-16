#include "Game.h"
#include <QApplication>
#include <QGraphicsScene>
#include "Player.h"
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QDebug>

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

    // create score
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // spawn enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //play background music
    QMediaPlayer* music = new QMediaPlayer();
    QAudioOutput* audio = new QAudioOutput();
    music->setAudioOutput(audio);
    music->setSource(QUrl("qrc:/sounds/external/bgm.mp3"));
    audio->setVolume(0.05);
    connect(music,&QMediaPlayer::mediaStatusChanged,music,&QMediaPlayer::play);
    music->play();

    show();
}


