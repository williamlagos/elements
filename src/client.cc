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

#include <client.h>

Module::Module(bool stat) {
    status = stat;
}

void Module::connect()
{
    // TODO: Code for connecting game server
    httplib::Client cli("openlibrary.org");
    auto res = cli.Get("/api/books?bibkeys=ISBN:0201558025,LCCN:93005405&format=json");

    if (res && res->status == 200) {
        std::string err;
        auto body = res->body;
        auto obj = Json::parse(body, err);
        std::cout << res->body << std::endl;
        std::cout << obj["LCCN:93005405"]["bib_key"].string_value() << std::endl;
    }
}

Euphoria::Euphoria(bool stat)
{
    name = "Naanphea";
	status = stat;
}
int Euphoria::startEngine()
{
	/* Option not implemented already */
    return 0;
}
int Euphoria::stopEngine()
{
	/* Option not implemented already */
    return 0;
}
bool Euphoria::getStatus()
{
    return status;
}

Naanphea::Naanphea(bool stat)
{
	name = "Naanphea";
	status = stat;
}
int Naanphea::startEngine()
{
	/* Option not implemented already */
    return 0;
}
int Naanphea::stopEngine()
{
	/* Option not implemented already */
    return 0;
}
bool Naanphea::getStatus()
{
    return status;
}


Elements::Elements(bool naanStatus, bool euphStatus)
{
	naanCore = new Naanphea(naanStatus);
	euphCore = new Euphoria(euphStatus);
	gameClasses.insert(std::pair<void*,bool>((void*)naanCore,naanCore->getStatus()));
	gameClasses.insert(std::pair<void*,bool>((void*)euphCore,euphCore->getStatus()));
}
int Elements::chooseGameClass(int gameType)
{
	switch(gameType){
	  case 2: gameClasses[(void*)euphCore] = true;
		  engineHandler = (void*)euphCore;
		  break;
	  case 3: gameClasses[(void*)naanCore] = true;
		  engineHandler = (void*)naanCore;
		  break;
	}
    return 0;
}
int Elements::callelementsModule()
{
	/* Option not implemented already */
    return 0;
}
void* Elements::getEngineHandler()
{
	return engineHandler;
}
void* Elements::getMicroModule()
{
    return NULL;
}
