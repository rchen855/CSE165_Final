#include "Headers/TankEnemy.h"
#include <QTimer>

TankEnemy::TankEnemy() : Enemy() {
    // Initialize health to 2 (same as before)
    Enemy::setHealth(3);

    // Initialize speed to 3 (slower than before)
    speed = 2;

    // Set position and pixmap
    setPixmap(QPixmap(":/images/external/tankenemy.png"));
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}
