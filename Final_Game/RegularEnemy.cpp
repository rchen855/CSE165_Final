FasterEnemy::FasterEnemy(): Enemy() {
    speed = 7; // Adjust speed for FasterEnemy
    setPixmap(QPixmap(":/images/external/fasterenemy.png"));
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}
