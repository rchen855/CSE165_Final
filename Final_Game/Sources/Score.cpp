#include "Headers/Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    // initialize score to 0
    score = 0;

    // draw the score
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

Score::~Score() {
    // Destructor
}

void Score::increase(int num) {
    score += num;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore() {
    return score;
}
