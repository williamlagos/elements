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

#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <map>
#include <string>
#include <vector>

using namespace std;

class Engine {
private:
    bool status;
public:
    Engine(bool stat = false);
    bool getStatus() const;
    int start();
    int stop();
};

class Element{
private:
    int speedX;
    int speedY;
    int width;
    int height;
    int posX;
    int posY;
    string name;
    double hitPoints;
public:
    Element(string n = "");
    void hurtElement(double);
    void healElement(double);
    void whichSize(int, int);
    void whichSpeed(int, int);
    void whichPosition(int, int);
    double getHitPoints() const;
    string getName() const;
    int getWidth() const;
    int getHeight() const;
    int getSpeedX() const;
    int getSpeedY() const;
    int getPositionX() const;
    int getPositionY() const;
};

class Elements {
private:
    Engine* core;
    void* engineHandler;
    std::vector<Element> sprites;
    std::map<void*, bool> gameClasses;
public:
    Elements();
    Elements(bool);
    ~Elements();
    int chooseGameClass(int);
    int callelementsModule();
    void* getEngineHandler();
    void* getMicroModule();
    void addElement(std::string);
    void remElement();
    int getElementCount() const;
    Element* getElement(int index);
    const std::vector<Element>& getElements() const;
};

#endif /* ELEMENTS_H */
