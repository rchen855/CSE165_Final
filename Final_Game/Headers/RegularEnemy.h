#ifndef REGULARENEMY_H
#define REGULARENEMY_H

#include "Headers/Enemy.h"

class RegularEnemy: public Enemy {
public:
    RegularEnemy();
    void move() override;
};

#endif // REGULARENEMY_H
