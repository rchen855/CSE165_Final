#include "Headers/Game.h"
#include "Headers/Player.h"
#include "Headers/Menu.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QDebug>
#include <QBrush>
#include <QImage>
#include <QGraphicsTextItem>
#include <QPushButton>

Game::Game(QWidget *parent) {
    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,800);

    // visualize game
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setBackgroundBrush(QBrush(QImage(":/images/external/bg.jpg")));
    setFixedSize(800,800);

    //play background music
    QMediaPlayer* music = new QMediaPlayer();
    QAudioOutput* audio = new QAudioOutput();
    music->setAudioOutput(audio);
    music->setSource(QUrl("qrc:/sounds/external/bgm.mp3"));
    audio->setVolume(0.05);
    connect(music,&QMediaPlayer::mediaStatusChanged,music,&QMediaPlayer::play);
    music->play();

    // create Player to put into the scene
    player = new Player();
    player->setPixmap(QPixmap(":/images/external/player.png"));
    player->setPos(375,600);

    // make item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));

}

void Game::backToMenu() {
    displayMenu();
}

void Game::easyGame() {
    scene->clear();
    Menu* backToMenu = new Menu(QString("Back to Menu"));
    int x = 600;
    int y = 0;
    backToMenu->setPos(x,y);
    connect(backToMenu, SIGNAL(clicked()),this,SLOT(backToMenu()));
    scene ->addItem(backToMenu);

    // add the item to the scene
    scene->addItem(player);

    // create score
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);
    timer->start(2000);
    show();
}

void Game::medGame() {
    scene->clear();
    Menu* backToMenu = new Menu(QString("Back to Menu"));
    int x = 600;
    int y = 0;
    backToMenu->setPos(x,y);
    connect(backToMenu, SIGNAL(clicked()),this,SLOT(backToMenu()));
    scene ->addItem(backToMenu);
    scene->addItem(player);

    // create score
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    timer->start(1500);
    show();
}

void Game::hardGame() {
    scene->clear();
    Menu* backToMenu = new Menu(QString("Back to Menu"));
    int x = 600;
    int y = 0;
    backToMenu->setPos(x,y);
    connect(backToMenu, SIGNAL(clicked()),this,SLOT(backToMenu()));
    scene ->addItem(backToMenu);
    scene->addItem(player);

    // create score
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // spawn enemies
    timer->start(1000);

    if (health->getHealth() < 0) {
        gameOver();
    }

    show();
}

void Game::displayMenu() {
    scene->clear();
    // title text
    QGraphicsTextItem* title = new QGraphicsTextItem(QString("Mushroom Kingdom"));
    QFont titleFont("comic sans",50);
    title->setFont(titleFont);
    int titleX = this->width()/2 - title->boundingRect().width()/2;
    int titleY = 150;
    title->setPos(titleX, titleY);
    scene->addItem(title);

    // easy button
    Menu* easy = new Menu(QString("Easy"));
    int easyX = this->width() / 2 - easy->boundingRect().width() / 2;
    int easyY = 275;
    easy->setPos(easyX, easyY);
    QObject::connect(easy, SIGNAL(clicked()), this, SLOT(easyGame()));
    scene->addItem(easy);

    // medium button
    Menu* med = new Menu(QString("Medium"));
    int medX = this->width() / 2 - med->boundingRect().width() / 2;
    int medY = 350;
    med->setPos(medX, medY);
    QObject::connect(med, SIGNAL(clicked()), this, SLOT(medGame()));
    scene->addItem(med);

    // hard button
    Menu* hard = new Menu(QString("Hard"));
    int hardX = this->width() / 2 - hard->boundingRect().width() / 2;
    int hardY = 425;
    hard->setPos(hardX, hardY);
    QObject::connect(hard, SIGNAL(clicked()), this, SLOT(hardGame()));
    scene->addItem(hard);

    // quit button
    Menu* quit = new Menu(QString("Quit"));
    int quitX = this-> width()/2 - quit->boundingRect().width()/2;
    int quitY = 500;
    quit-> setPos(quitX, quitY);
    connect(quit, SIGNAL(clicked()),this,SLOT(close()));
    scene ->addItem(quit);
}

void Game::gameOver() {
    timer->stop();
    // title text
    QGraphicsTextItem* gameOver = new QGraphicsTextItem(QString("Game Over!"));
    QFont gameOverFont("comic sans",50);
    gameOver->setDefaultTextColor(Qt::red);
    gameOver->setFont(gameOverFont);
    int gameOverX = this->width()/2 - gameOver->boundingRect().width()/2;
    int gameOverY = 150;
    gameOver->setPos(gameOverX, gameOverY);
    scene->addItem(gameOver);

    // // quit button
    Menu* quit = new Menu(QString("Quit"));
    int quitX = this-> width()/2 - quit->boundingRect().width()/2;
    int quitY = 275;
    quit-> setPos(quitX, quitY);
    connect(quit, SIGNAL(clicked()),this,SLOT(close()));
    scene ->addItem(quit);

}


