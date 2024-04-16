#include "Headers/Menu.h"
#include <QBrush>

Menu::Menu(QString name, QGraphicsItem* parent): QGraphicsRectItem() {
    // making button
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::Dense2Pattern);
    brush.setColor(Qt::blue);
    setBrush(brush);

    // make text
    text = new QGraphicsTextItem(name, this);
    int x = rect().width() / 2 - text->boundingRect().width() / 2;
    int y = rect().height() / 2 - text->boundingRect().height() / 2;
    text->setPos(x,y);
    setAcceptHoverEvents(true);
}

void Menu::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    emit clicked();
}

void Menu::hoverEnterEvent(QGraphicsSceneHoverEvent* event) {
    QBrush brush;
    brush.setStyle(Qt::Dense2Pattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

void Menu::hoverLeaveEvent(QGraphicsSceneHoverEvent* event) {
    QBrush brush;
    brush.setStyle(Qt::Dense2Pattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
}
