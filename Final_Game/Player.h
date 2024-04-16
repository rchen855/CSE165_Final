#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player(QGraphicsItem* parent=0);
    void keyPressEvent(QKeyEvent* event);
public slots:
    void spawn();
private:
    QMediaPlayer* bulletsound;
    QAudioOutput* audio;
};


#endif // PLAYER_H
