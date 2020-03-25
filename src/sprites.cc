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

#include <elements.h>

class Element {
private:
    std::string name;
    double hitPoints;
    int height;
    int width;
    int speed;
public:
    Element(std::string);
    void hurtElement(double);
    void healElement(double);
    void whichSize(int, int);
    void whichSpeed(int, int);
};

Element::Element(std::string n)
{
	name = n;
//	sprImage = spriteImage();
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

class Elements {
private:
    Element* sprites;
    Element* last;
    Element* init;
    int elemCount;
public:
    Elements();
    void addElement(std::string);
    void remElement();
};

Elements::Elements()
{
//	Scene *sce = new Scene();
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
