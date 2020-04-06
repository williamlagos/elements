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
//#include <graphics.h>

using namespace std;

class Euphoria {
private:
    bool status;
public:
    Euphoria(bool);
    bool getStatus();
    int startEngine();
    int stopEngine();
};

class Naanphea {
private:
    bool status;
public:
    Naanphea(bool);
    bool getStatus();
    int startEngine();
    int stopEngine();
};

class Element{ //Elements
private:
    int* speed;
    int width;
    int height;
    int position;
    string name;
    double hitPoints;
//    Geometry* sprImage;
public:
    Element(string);
//    Geometry* spriteImage();
    void hurtElement(double);
    void healElement(double);
    void whichSize(int,int);
    void whichSpeed(int,int);
//    void update(Scene*);
};

class Elements {
private:
    Naanphea* naanCore;
    Euphoria* euphCore;
    void* engineHandler;
    Element* sprites;
    Element* last;
    Element* init;
    int elemCount;
    std::map<void*, bool> gameClasses;
public:
    Elements();
    Elements(bool, bool);
    int chooseGameClass(int);
    int callelementsModule();
    void* getEngineHandler();
    void* getMicroModule();
    void addElement(std::string);
    void remElement();
};

#endif /* ELEMENTS_H */
