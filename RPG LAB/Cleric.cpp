//
//  Cleric.cpp
//  RPG
//
//  Created by Christian Guthrie on 1/28/17.
//  Copyright © 2017 Christian Guthrie. All rights reserved.
//

#include "Cleric.h"


Cleric::Cleric(std::string newName, int newMaxHP, int newStrength, int newSpeed, int newMage) : Fighter(newName, newMaxHP, newStrength, newSpeed, newMage) {
    name = newName;
    maxHP = newMaxHP;
    strength = newStrength;
    speed = newSpeed;
    mage = newMage;
    maxMana = 5 * mage;
    currentMana = maxMana;
}
Cleric::~Cleric(){
    
}


void Cleric::regenerate() {
    int minMage = 5;
    
    Fighter::regenerate();
    
    if (mage < minMage) {
        currentMana += 1;
    }
    else {
        currentMana += (mage / 5);
    }
    
    if (currentMana > maxMana) {
        currentMana = maxMana;
    }
}

int Cleric::getDamage() {
    return mage;
}

void Cleric::reset() {
    Fighter::reset();
    
    currentMana = maxMana;
}


bool Cleric::useAbility() {
    int minMage = 3;
    
    if (currentMana >= CLERIC_ABILITY_COST) {
        currentMana -= CLERIC_ABILITY_COST;
        if (mage < minMage) {
            currentHP += 1;
        }
        else {
            currentHP += mage / 3;
        }
        
        if (currentHP > maxHP) {
            currentHP = maxHP;
        }
        return true;
    }
    else return false;
}






//