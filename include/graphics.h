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

#include <GLUT/glut.h>
#ifndef __APPLE__
 #include <GL/gl.h>
 #include <GL/glu.h>
#else
 #include <OpenGL/gl.h>
 #include <OpenGL/glu.h>
#endif
//#include <Box2D/Box2D.h>
#include <time.h>

extern int main_window;
extern int width, height;
extern float x,y,z;

void init();
void display();
void reshape(int w, int h);
int start_engine(int argc,char **argv);
