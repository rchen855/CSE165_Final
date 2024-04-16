#ifndef FASTERENEMY_H
#define FASTERENEMY_H

#include "Headers/Enemy.h"

class FasterEnemy: public Enemy {
public:
    FasterEnemy();
    void move() override;
};


#endif // FASTERENEMY_H
