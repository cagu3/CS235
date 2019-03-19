//
//  Arena.cpp
//  RPG
//
//  Created by Christian Guthrie on 1/25/17.
//  Copyright © 2017 Christian Guthrie. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Arena.h"



Arena::Arena() {
    std::vector<FighterInterface*> fighterList;
}
Arena::~Arena() {
    
}


/*
 *	addFighter(string)
 *
 *	Adds a new fighter to the collection of fighters in the arena. Do not allow
 *	duplicate names.  Reject any string that does not adhere to the format
 *	outlined in the lab specs.
 *
 *	Return true if a new fighter was added; false otherwise.
 */
bool Arena::addFighter(std::string info) {
    std::stringstream ss(info);
    
    std::string name;
    char type;
    int maxHP;
    int strength;
    int speed;
    int mage;
    int fail;
    
    ss >> name;
    if (ss.fail()) {
        return false;
    }
    ss >> type;
    if (ss.fail()) {
        return false;
    }
    ss >> maxHP;
    if (ss.fail()) {
        return false;
    }
    ss >> strength;
    if (ss.fail()) {
        return false;
    }
    ss >> speed;
    if (ss.fail()) {
        return false;
    }
    ss >> mage;
    if (ss.fail()) {
        return false;
    }
    ss >> fail;
    if (!ss.fail()) {
        return false;
    }
    
    for (int i = 0; i < fighterList.size(); i++) {
        if (name == fighterList[i]->getName()) {
            return false;
        }

    }
    
    if (type == 'A') {
        FighterInterface* aptr = new Archer(name, maxHP, strength, speed, mage);
        fighterList.push_back(aptr);
        return true;
    }
    else if (type == 'C') {
        FighterInterface* cptr = new Cleric(name, maxHP, strength, speed, mage);
        fighterList.push_back(cptr);
        return true;
    }
    else if (type == 'R') {
        FighterInterface* rptr = new Robot(name, maxHP, strength, speed, mage);
        fighterList.push_back(rptr);
        return true;
    }
    else return false;
     

}

/*
 *	removeFighter(string)
 *
 *	Removes the fighter whose name is equal to the given name.  Does nothing if
 *	no fighter is found with the given name.
 *
 *	Return true if a fighter is removed; false otherwise.
 */
bool Arena::removeFighter(std::string name) {
    int placement = 0;
    bool check = false;
    
    for (int i = 0; i < fighterList.size(); i++) {
        if (fighterList[i]->getName() == name) {
            check = true;
            placement = i;
        }
    }
    
    if (check == true) {
        fighterList.erase(fighterList.begin() + placement);
        return true;
    }
    else return false;
    
}

/*
 *	getFighter(string)
 *
 *	Returns the memory address of a fighter whose name is equal to the given
 *	name.  Returns NULL if no fighter is found with the given name.
 *
 *	Return a memory address if a fighter is found; NULL otherwise.
 */
FighterInterface* Arena::getFighter(std::string name) {
    
    for (int i = 0; i < fighterList.size(); i++) {
        if (fighterList[i]->getName() == name) {
            return fighterList[i];
        }
    }
    return NULL;
}

/*
 *	getSize()
 *
 *	Returns the number of fighters in the arena.
 *
 *	Return a non-negative integer.
 */
int Arena::getSize() const {
    return fighterList.size();
}









