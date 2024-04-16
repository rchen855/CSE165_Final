#ifndef TANKENEMY_H
#define TANKENEMY_H

#include "Enemy.h"

class TankEnemy : public Enemy {
public:
    TankEnemy();
    void move() override;
};

#endif // TANKENEMY_H
