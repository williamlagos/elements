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

#ifndef CLIENT_H
#define CLIENT_H

#include <map>
#include <fstream>
#include <iostream>
#include <modules.h>
#include <httplib.h>
#include <wslib.h>
#include <json.h>

using namespace json11;
using namespace std;

typedef std::map<std::string,const char*> Value;

class FastWriter{
public:
    FastWriter();
    std::string write(Value&);
};

class Reader{
public:
    Reader();
    void parse(std::string,Value&);
};

class Client {
private:
    bool status;
public:
    Client(bool);
    void connectServer();
    void parseJson(const char*);
};

class Player {
private:
    View* view;
public:
    Player();
};

#endif /* CLIENT_H */
