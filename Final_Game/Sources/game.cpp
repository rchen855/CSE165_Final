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

void Game::tutorial() {
    scene->clear();
    Menu* backToMenu = new Menu(QString("Back to Menu"));
    int x = 595;
    int y = 5;
    backToMenu->setPos(x,y);
    connect(backToMenu, SIGNAL(clicked()),this,SLOT(backToMenu()));
    scene ->addItem(backToMenu);

    // Makes the title
    QGraphicsTextItem* title = new QGraphicsTextItem(QString("Mushroom Kingdom"));
    QFont titleFont("comic sans",50);
    title->setFont(titleFont);
    int titleX = this->width()/2 - title->boundingRect().width()/2;
    int titleY = 150;
    title->setPos(titleX, titleY);
    scene->addItem(title);

    // Controls
    QGraphicsTextItem* controls = new QGraphicsTextItem();
    controls->setPlainText("Controls: \n\t- Use WASD or arrow keys to move\n\t- Use spacebar to shoot\nMonsters:\n\t- Normal:\n\t\t1 HP, medium speed, 1 point\n\t- Fast:\n\t\t1 HP, fast speed, 3 points\n\t- Tank:\n\t\t3 HP, slow speed, 5 points"
                           "\nDifficulties:\n\t- Easy: slow spawn rate\n\t- Medium: medium spawn rate\n\t- Hard: fast spawn rate");
    controls->setDefaultTextColor(Qt::white);
    controls->setFont(QFont("times",20));
    int controlsX = this->width()/2 - controls->boundingRect().width()/2;
    int controlsY = 225;
    controls->setPos(controlsX, controlsY);
    scene->addItem(controls);

}

void Game::easyGame() {
    scene->clear();
    Menu* backToMenu = new Menu(QString("Back to Menu"));
    int x = 595;
    int y = 5;
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
    int x = 595;
    int y = 5;
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
    int x = 595;
    int y = 5;
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

    // tutorial button
    Menu* tut = new Menu(QString("Tutorial"));
    int tutX = this->width() / 2 - tut->boundingRect().width() / 2;
    int tutY = 275;
    tut->setPos(tutX, tutY);
    QObject::connect(tut, SIGNAL(clicked()), this, SLOT(tutorial()));
    scene->addItem(tut);

    // easy button
    Menu* easy = new Menu(QString("Easy"));
    int easyX = this->width() / 2 - easy->boundingRect().width() / 2;
    int easyY = 350;
    easy->setPos(easyX, easyY);
    QObject::connect(easy, SIGNAL(clicked()), this, SLOT(easyGame()));
    scene->addItem(easy);

    // medium button
    Menu* med = new Menu(QString("Medium"));
    int medX = this->width() / 2 - med->boundingRect().width() / 2;
    int medY = 425;
    med->setPos(medX, medY);
    QObject::connect(med, SIGNAL(clicked()), this, SLOT(medGame()));
    scene->addItem(med);

    // hard button
    Menu* hard = new Menu(QString("Hard"));
    int hardX = this->width() / 2 - hard->boundingRect().width() / 2;
    int hardY = 500;
    hard->setPos(hardX, hardY);
    QObject::connect(hard, SIGNAL(clicked()), this, SLOT(hardGame()));
    scene->addItem(hard);

    // quit button
    Menu* quit = new Menu(QString("Quit"));
    int quitX = this-> width()/2 - quit->boundingRect().width()/2;
    int quitY = 575;
    quit-> setPos(quitX, quitY);
    connect(quit, SIGNAL(clicked()),this,SLOT(close()));
    scene ->addItem(quit);
}

void Game::gameOver() {
    timer->stop();
    for (int i = 0; i < scene->items().size(); i++) {
        if (typeid(*(items()[i])) != typeid(Score)) {
            scene->items()[i]->setEnabled(false);
            scene->items()[i]->setOpacity(0);
        }
    }
    QMediaPlayer* music = new QMediaPlayer();
    QAudioOutput* audio = new QAudioOutput();
    music->setAudioOutput(audio);
    music->setSource(QUrl("qrc:/sounds/external/gameover.mp3"));
    audio->setVolume(0.75);
    music->play();
    // title text
    QGraphicsTextItem* gameOver = new QGraphicsTextItem(QString("Game Over!"));
    QFont gameOverFont("comic sans",50);
    gameOver->setDefaultTextColor(Qt::red);
    gameOver->setFont(gameOverFont);
    int gameOverX = this->width()/2 - gameOver->boundingRect().width()/2;
    int gameOverY = 275;
    gameOver->setPos(gameOverX, gameOverY);
    scene->addItem(gameOver);
    int sX = (this->width()/2 - gameOver->boundingRect().width()/2) + 125;
    int sY = 350;
    score->setPos(sX,sY);

    // // quit button
    Menu* quit = new Menu(QString("Quit"));
    int quitX = this-> width()/2 - quit->boundingRect().width()/2;
    int quitY = 390;
    quit-> setPos(quitX, quitY);
    connect(quit, SIGNAL(clicked()),this,SLOT(close()));
    scene ->addItem(quit);

}


