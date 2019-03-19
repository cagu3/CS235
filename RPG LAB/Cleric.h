//
//  Cleric.h
//  RPG
//
//  Created by Christian Guthrie on 1/28/17.
//  Copyright © 2017 Christian Guthrie. All rights reserved.
//

#ifndef Cleric_h
#define Cleric_h

#include <stdio.h>
#include "Fighter.h"

class Cleric : public Fighter
{
public:
    Cleric(std::string name, int maxHP, int strength, int speed, int mage);
    ~Cleric();
    
    void regenerate();
    int getDamage();
    void reset();
    bool useAbility();
    
protected:
    int currentMana;
    int maxMana;
    
};

#endif /* Cleric_h */
