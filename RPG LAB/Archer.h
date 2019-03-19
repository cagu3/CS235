//
//  Archer.h
//  RPG
//
//  Created by Christian Guthrie on 1/28/17.
//  Copyright © 2017 Christian Guthrie. All rights reserved.
//

#ifndef Archer_h
#define Archer_h

#include <string>
#include <stdio.h>
#include "Fighter.h"

using namespace std;
class Archer : public Fighter
{
public:
    Archer(std::string name, int maxHP, int strength, int speed, int mage);
    ~Archer();
    
    int getDamage();
    void reset();
    bool useAbility();
    
protected:
    int originalSpeed;

};

    


#endif /* Archer_h */
