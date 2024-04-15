#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    // initialize score to 0
    score = 0;

    // draw the score
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase() {
    score++;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore() {
    return score;
}
