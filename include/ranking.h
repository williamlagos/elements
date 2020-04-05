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

#ifndef RANKING_H
#define RANKING_H

#include <string>
#include <sstream>
#include <iostream>
#include <tree.h>

#define BLACK 0
#define WHITE 1
#define GRAY 2

using namespace std;

class Codes
{
private:
    tree<int> code;
    tree<int>::iterator root, target;
public:
    Codes();
    ~Codes();
    int blacks();
    vector<int> sourceTree();
    string      printTree();
    string      parseCode(string);
    string      black();
    string      white();
    string      gray();
    void        clearTree();
};

#endif /* RANKING_H */
