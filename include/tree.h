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

#ifndef TREE_H
#define TREE_H

#include <string>
#include <iostream>

using namespace std;

enum treePrints{
    IN_ORDER = 1,
    PRE_ORDER = 2,
    POST_ORDER = 3
};

struct Content
{
    string data;
};

struct Node
{
    Node* left;
    Node* right;
    Content* data;
};

class Tree{
private:
    Node* root;
public:
    Tree(){ root = NULL; }
    Node* getRoot(){ return root; }
    bool isEmpty() const { return root==NULL; }
    void print(int);
    void inOrder(Node*);
    void preOrder(Node*);
    void postOrder(Node*);
    void insert(Content*);
    void remove(string);
};

#endif /* TREE_H */
