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

Engine::Engine(bool stat)
{
    status = stat;
}
int Engine::start()
{
    return 0;
}
int Engine::stop()
{
    return 0;
}
bool Engine::getStatus() const
{
    return status;
}

Element::Element(std::string n)
    : speedX(0), speedY(0), width(16), height(16), posX(0), posY(0), name(n), hitPoints(100.0)
{
}

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
    speedX = xAxis;
    speedY = yAxis;
}

void Element::whichPosition(int x, int y)
{
    posX = x;
    posY = y;
}

double Element::getHitPoints() const
{
    return hitPoints;
}

string Element::getName() const
{
    return name;
}

int Element::getWidth() const
{
    return width;
}

int Element::getHeight() const
{
    return height;
}

int Element::getSpeedX() const
{
    return speedX;
}

int Element::getSpeedY() const
{
    return speedY;
}

int Element::getPositionX() const
{
    return posX;
}

int Element::getPositionY() const
{
    return posY;
}

Elements::Elements()
    : core(new Engine(false)), engineHandler(nullptr)
{
}

Elements::Elements(bool status)
    : core(new Engine(status)), engineHandler(nullptr)
{
    gameClasses.insert(std::pair<void*,bool>((void*)core, core->getStatus()));
}

Elements::~Elements()
{
    delete core;
}

int Elements::chooseGameClass(int gameType)
{
    switch(gameType){
      case 2: gameClasses[(void*)core] = true;
          engineHandler = (void*)core;
          break;
    }
    return 0;
}

int Elements::callelementsModule()
{
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

void Elements::addElement(std::string n)
{
    sprites.emplace_back(n);
}

void Elements::remElement()
{
    if(!sprites.empty()){
        sprites.pop_back();
    }
}

int Elements::getElementCount() const
{
    return static_cast<int>(sprites.size());
}

Element* Elements::getElement(int index)
{
    if(index >= 0 && index < static_cast<int>(sprites.size())){
        return &sprites[index];
    }
    return nullptr;
}

const std::vector<Element>& Elements::getElements() const
{
    return sprites;
}

