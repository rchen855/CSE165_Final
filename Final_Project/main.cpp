#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,800);

    // create an item to put into the scene
    MyRect* player = new MyRect();
    player->setRect(0,0,100,100);
    player->setPos(375,600);

    // make item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add the item to the scene
    scene->addItem(player);

    // add a view
    QGraphicsView* view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setBackgroundBrush(Qt::white);
    view->setFixedSize(800,800);
    view->show();

    return a.exec();
}
