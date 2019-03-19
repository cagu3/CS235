//
//  Robot.cpp
//  RPG
//
//  Created by Christian Guthrie on 1/28/17.
//  Copyright © 2017 Christian Guthrie. All rights reserved.
//

#include <cmath>


#include "Robot.h"


Robot::Robot(std::string newName, int newMaxHP, int newStrength, int newSpeed, int newMage) : Fighter(newName, newMaxHP, newStrength, newSpeed, newMage) {
    name = newName;
    maxHP = newMaxHP;
    strength = newStrength;
    speed = newSpeed;
    mage = newMage;
    maxEnergy = 2 * mage;
    currentEnergy = maxEnergy;
    bonusDamage = 0;
}
Robot::~Robot() {
    
}

int Robot::getDamage() {
    int damage;
    damage = strength + bonusDamage;
    bonusDamage = 0;
    
    return damage;
}

void Robot::reset() {
    Fighter::reset();
    
    currentEnergy = maxEnergy;
    bonusDamage = 0;
}


/*
 *  Robot: Shockwave Punch
 *  Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_energy/maximum_energy)^4)).
 *  Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
 *  Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
 *      Examples:
 *      strength=20, current_energy=20, maximum_energy=20       => bonus_damage=20
 *      strength=20, current_energy=15, maximum_energy=20       => bonus_damage=6
 *      strength=20, current_energy=10, maximum_energy=20       => bonus_damage=1
 *      strength=20, current_energy=5,  maximum_energy=20       => bonus_damage=0
 *  Robot Note:
 *  The bonus damage formula should be computed using double arithmetic, and only
 *  the final result should be cast into an integer.
*/
bool Robot::useAbility() {
    double dBonusDamage = bonusDamage;
    double dStrength = strength;
    double dCurrentEnergy = currentEnergy;
    double dMaxEnergy = maxEnergy;
    
    if (currentEnergy >= ROBOT_ABILITY_COST) {
        dBonusDamage = dStrength * pow((dCurrentEnergy/dMaxEnergy),4);
        bonusDamage = dBonusDamage;
        currentEnergy -= ROBOT_ABILITY_COST;
        return true;
    }
    else return false;
}









//