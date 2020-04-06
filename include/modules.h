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

#ifndef MODULES_H
#define MODULES_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#include <tree.h>

using namespace std;

struct Info{
	string name;
	string vers;
	int month;
	int year;
};

class Error{
public:
	Error();
	string getMessage();
};

class Sample{
public:
	Sample(string);
	int get();
};

class Module{
protected:
    string name;
    bool status;
public:
    Module(string,bool);
    string getName();
    bool getStatus();
    int operator > (Module);
    int operator < (Module);
    void setStatus();
};

class Library : public Module{
public:
    Library(string);
};

class Package{
private:
    Module* init;
    Module* last;
    vector<Module> modules;
    int addModule(Module*);
public:
    Package(){};
    int numOfModules();
};

struct Structure
{
    Tree mainTree;
    queue<Module> modExec;
    stack<Package> pakStack;
};

extern Structure baseStr;

Package accessPackage(string);
int newPackage(int);
int exeModule(string);
bool ZhockonInit();
void readConfig();
void createGame(string);
void deleteGame(string);
void listModules();

#endif /* MODULES_H */
