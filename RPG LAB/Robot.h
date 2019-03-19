//
//  Robot.h
//  RPG
//
//  Created by Christian Guthrie on 1/28/17.
//  Copyright © 2017 Christian Guthrie. All rights reserved.
//

#ifndef Robot_h
#define Robot_h

#include <stdio.h>
#include "Fighter.h"

class Robot : public Fighter
{
public:
    Robot(std::string name, int maxHP, int strength, int speed, int mage);
    ~Robot();
    
    int getDamage();
    void reset();
    bool useAbility();
    
protected:
    int maxEnergy;
    int currentEnergy;
    int bonusDamage;
    
    
};

#endif /* Robot_h */
