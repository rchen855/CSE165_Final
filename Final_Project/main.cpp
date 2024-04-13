#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene* scene = new QGraphicsScene();

    // create an item to put into the scene
    MyRect* rect = new MyRect();
    rect->setRect(0,0,100,100);

    // make item focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // add the item to the scene
    scene->addItem(rect);

    // add a view
    QGraphicsView* view = new QGraphicsView(scene);
    view->show();

    return a.exec();
}
