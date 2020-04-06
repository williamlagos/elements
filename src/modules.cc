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

#include <modules.h>

Structure baseStr;
Info infoVer;

string Error::getMessage()
{
  
}


Module::Module(string modName, bool modStatus=true)
{
	name = modName;
	status = modStatus;
}

string Module::getName()
{
	return name;
}
bool Module::getStatus()
{
	return status;
}
void Module::setStatus()
{
	status = ~status;
}
int Module::operator > (Module mod)
{
	return name.compare(mod.getName());
}
int Module::operator < (Module mod)
{
	return mod.getName().compare(name);
}


int Package::addModule(Module* mod)
{
	modules.push_back((*mod));
	return 0;
}
int Package::numOfModules()
{
	return modules.size();
}


Handler::Handler() {
    
}

bool Handler::Init()
{
	Node* root = baseStr.mainTree.getRoot();
	/*string Packages[3] = {"Elements","Ranking","Network"};
	newPackage((string*)Packages,3);*/
	readConfig();
	return true;
}

int Handler::newPackage(int times)
{
	for(int i = 0; i < times; i++){
		Package lay;
		baseStr.pakStack.push(lay);
	}
}

Package Handler::accessPackage(string value)
{
	stack<Package> stackTemp = baseStr.pakStack;
	while(!stackTemp.empty()){
		//if(name.compare(stackTemp.top().getName()) == 0){
			return stackTemp.top();
		//}
	}
	stackTemp.pop();
}

void Handler::createGame(string gamName)
{
    Content *newGame = new Content();
	baseStr.mainTree.insert(newGame);
}

void Handler::deleteGame(string gamName)
{
	baseStr.mainTree.remove(gamName);
}

int Handler::exeModule(string name)
{
	Module mod(name,true);
	baseStr.modExec.push(mod);
}

void Handler::listModules()
{
	baseStr.mainTree.print(1);
}

void Handler::readConfig()
{
	/*Python p("Configuration");
	p.loadModule("ConfigParser");
	p.newObject("ConfigParser","");*/
}
