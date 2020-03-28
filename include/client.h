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

#ifndef client_h
#define client_h

#include <map>
#include <iostream>
#include <httplib.h>
#include <wslib.h>
#include <json.h>

using namespace json11;

class Module {
private:
    bool status;
public:
    Module(bool);
    void connect();
};

class Euphoria {
private:
    std::string name;
    bool status;
public:
    Euphoria(bool);
    bool getStatus();
    int startEngine();
    int stopEngine();
};

class Naanphea {
private:
    std::string name;
    bool status;
public:
    Naanphea(bool);
    bool getStatus();
    int startEngine();
    int stopEngine();
};

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

#endif /* client_h */
