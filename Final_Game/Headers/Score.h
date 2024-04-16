#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem {
public:
    Score(QGraphicsItem* parent=0);
    ~Score();
    void increase(int num);
    int getScore();
private:
    int score;
};

#endif // SCORE_H
