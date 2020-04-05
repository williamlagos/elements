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
 * along with elements. If not, see <http://www.gnu.org/licenses/>.
 */

#include <elements.h>

Euphoria::Euphoria(bool stat)
{
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
bool Euphoria::getStatus()
{
    return status;
}

Naanphea::Naanphea(bool stat)
{
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
bool Naanphea::getStatus()
{
    return status;
}


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

Element::Element(std::string n)
{
    name = n;
//    sprImage = spriteImage();
}

/*Geometry* Element::spriteImage()
{
    Geometry* sprImg = new Geometry();
    return sprImg;
}*/

void Element::hurtElement(double hurtPoints)
{
    hitPoints -= hurtPoints;
}
void Element::healElement(double healPoints)
{
    hitPoints += healPoints;
}
void Element::whichSize(int newWidth, int newHeight)
{
    width = newWidth;
    height = newHeight;
}
void Element::whichSpeed(int xAxis, int yAxis)
{
    speed = xAxis;
    speed++;
    speed = yAxis;
}
/*void Element::update(Scene* sce)
{
    sce->drawScene();
}*/

Elements::Elements()
{
//    Scene *sce = new Scene();
    elemCount = 0;
}

void Elements::addElement(std::string n)
{
    if(sprites){
        sprites++;
        sprites = new Element(n);
        last = sprites;
    }else{
        init = sprites;
        sprites = new Element(n);
    }
    elemCount++;
}
void Elements::remElement()
{
    Element* removed;
    if(sprites){
        removed = last;
        delete removed;
        last--; elemCount--;
    }
}

