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

#include <ranking.h>
#include <sstream>
#include <iostream>
#include "../vendor/tree.hh"

struct Codes::Impl {
    tree<int> code;
    tree<int>::iterator root, target;
};

Codes::Codes() : pImpl(std::make_shared<Impl>())
{
    pImpl->root = pImpl->code.begin();
    pImpl->target = pImpl->code.insert(pImpl->root, GRAY);
}

Codes::~Codes() = default;

string Codes::black()
{
    if(pImpl->code.number_of_children(pImpl->target) == 4) return "Quadros preto/branco demais num quadrante";
    pImpl->code.append_child(pImpl->target, BLACK);
    return printTree();
}

string Codes::white()
{
    if(pImpl->code.number_of_children(pImpl->target) >= 4) return "Quadros preto/branco demais num quadrante";
    pImpl->code.append_child(pImpl->target, WHITE);
    return printTree();
}

string Codes::gray()
{
    tree<int>::iterator node, source;
    source = pImpl->code.insert(pImpl->code.end()--, GRAY);
    node = pImpl->code.append_child(source, GRAY);
    pImpl->code.append_child(source, GRAY);
    pImpl->code.append_child(source, GRAY);
    pImpl->code.move_before(pImpl->target, source);
    pImpl->target = node;
    return printTree();
}

string Codes::parseCode(std::string text)
{
    string message = "";
    for(char c : text){
        switch(c){
        case 'b':
            message = white();
            break;
        case 'p':
            message = black();
            break;
        case 'c':
            message = gray();
            break;
        default:
            message = "Token desconhecido!";
            break;
        }
    }
    return message;
}

void Codes::clearTree()
{
    pImpl->code.clear();
    printTree();
    pImpl->root = pImpl->code.begin();
    pImpl->target = pImpl->code.insert(pImpl->root, GRAY);
}

string Codes::printTree()
{
    string str = "";
    vector<int> v = sourceTree();
    for(int val : v){
        ostringstream oss;
        oss << val;
        str.append(oss.str());
    }
    return str;
}

vector<int> Codes::sourceTree()
{
    vector<int> v;
    for(auto it = pImpl->code.begin(); it != pImpl->code.end(); ++it)
        v.push_back(*it);
    return v;
}

int Codes::blacks()
{
    int count = 0;
    for(auto it = pImpl->code.begin(); it != pImpl->code.end(); ++it){
        if((*it) == BLACK) count++;
    }
    return count;
}

