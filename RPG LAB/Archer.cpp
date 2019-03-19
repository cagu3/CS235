//
//  Archer.cpp
//  RPG
//
//  Created by Christian Guthrie on 1/28/17.
//  Copyright © 2017 Christian Guthrie. All rights reserved.
//

#include "Archer.h"


Archer::Archer(std::string newName, int newMaxHP, int newStrength, int newSpeed, int newMage):Fighter(newName, newMaxHP, newStrength, newSpeed, newMage) {
    
    originalSpeed=speed;
}

Archer::~Archer() {
    
    
}

int Archer::getDamage() {
    return speed;
}

void Archer::reset() {
    Fighter::reset();
    
    speed = originalSpeed;
}



bool Archer::useAbility() {
    speed += 1;
    return true;
}