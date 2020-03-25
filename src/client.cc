/*
 * This file is part of elements project.
 * 
 * Copyright (C) 2009-2011 William Oliveira de Lagos <william.lagos@icloud.com>
 *
 * Elements is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Elements is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with elements.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "elements.h"
#include <map>
//#include "euphoria.h"

class Module {
private:
    bool status;
public:
    Module(bool);
    bool getStatus();
};

Module::Module(bool stat) {
    status = stat;
}

bool Module::getStatus()
{
    return status;
}

class Euphoria : public Module {
private:
    std::string name;
    bool status;
public:
    Euphoria(bool);
    int startEngine();
    int stopEngine();
};

class Naanphea : public Module {
private:
    std::string name;
    bool status;
public:
    Naanphea(bool);
    int startEngine();
    int stopEngine();
};

Euphoria::Euphoria(bool stat) : Module(stat)
{
    name = "Naanphea";
	status = stat;
}
int Euphoria::startEngine()
{
	/* Option not implemented already */
    return 0;
}
int Euphoria::stopEngine()
{
	/* Option not implemented already */
    return 0;
}

Naanphea::Naanphea(bool stat) : Module(stat)
{
	name = "Naanphea";
	status = stat;
}
int Naanphea::startEngine()
{
	/* Option not implemented already */
    return 0;
}
int Naanphea::stopEngine()
{
	/* Option not implemented already */
    return 0;
}

class Elements {
private:
    Naanphea* naanCore;
    Euphoria* euphCore;
    void* engineHandler;
    std::map<void*, bool> gameClasses;
public:
    Elements(bool, bool);
    int chooseGameClass(int);
    int callelementsModule();
    void* getEngineHandler();
    void* getMicroModule();
};

Elements::Elements(bool naanStatus, bool euphStatus)
{
	naanCore = new Naanphea(naanStatus);
	euphCore = new Euphoria(euphStatus);
	gameClasses.insert(std::pair<void*,bool>((void*)naanCore,naanCore->getStatus()));
	gameClasses.insert(std::pair<void*,bool>((void*)euphCore,euphCore->getStatus()));
}
int Elements::chooseGameClass(int gameType)
{
	switch(gameType){
	  case 2: gameClasses[(void*)euphCore] = true;
		  engineHandler = (void*)euphCore;
		  break;
	  case 3: gameClasses[(void*)naanCore] = true;
		  engineHandler = (void*)naanCore;
		  break;
	}
    return 0;
}
int Elements::callelementsModule()
{
	/* Option not implemented already */
    return 0;
}
void* Elements::getEngineHandler()
{
	return engineHandler;
}
void* Elements::getMicroModule()
{
    return NULL;
}
