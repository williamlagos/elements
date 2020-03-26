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

#include <httplib.h>
#include <wslib.h>
#include <main.h>
#include <json.h>
#include <iostream>

using namespace std;
using namespace json11;

int connect(int argc,char* argv[])
{
    // TODO: Code for connecting game server
    
	/*createGame("Hello World");
	SDL *sdlHandler = new SDL("HW",0,0);
	sdlHandler->baseMove();
	Python p("Test");
	p.helloPython();*/
	return 0;
}

int main(int argc, char *argv[])
{
    // TODO: Code for starting client
    
    /* Toolbox_malloc  = (void *(__cdecl *)(size_t))malloc;
    Toolbox_calloc  = (void *(__cdecl *)(size_t,size_t))calloc;
    Toolbox_realloc = (void *(__cdecl *)(void*,size_t))realloc;
    Toolbox_free    = (void (__cdecl *)(void *))free;
    QApplication a(argc, argv);
    AERoshell *poAERoshell = new AERoshell(&a);
    int nReturnCode = a.exec();
    delete poAERoshell; */

    // IMPORTANT: 1st parameter must be a hostname or an IP adress string.
    httplib::Client cli("openlibrary.org");

    auto res = cli.Get("/api/books?bibkeys=ISBN:0201558025,LCCN:93005405&format=json");

    if (res && res->status == 200) {
        string err;
        auto body = res->body;
        auto obj = Json::parse(body, err);
        std::cout << res->body << std::endl;
        std::cout << obj["LCCN:93005405"]["bib_key"].string_value() << std::endl;
    }
    cout << "Hello World!" << endl;
//    int abc = 0;
    return 0;
}
