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

#include <network.h>
//using namespace Json;

Adapter::Adapter(string name){
//	networking::init();
	adapterName = name;
}
Adapter::~Adapter()
{
//	networking::cleanup();
}

bool Adapter::Init()
{
//	pthread_t adapterServerThread;
//	pthread_create(&adapterServerThread,NULL,ManagerThread,NULL);
}
string Adapter::methodCall(char* methodName){
	//SubjectThread Init
	/*pthread_t adapterClientThread;
	pthread_create(&adapterClientThread,NULL,
		       SubjectThread,(void*)methodName);
	return string(methodName);*/
	
	FastWriter writer;
	Reader read;
	Value query;
	string quryString;
	string rpseString;
//	query["jsonrpc"] = JSONRPC_VERSION;
//	query["id"] = STD_ID;
//	query["method"] = methodName;
	quryString = writer.write(query);
//	Rpc::TcpClient* Sender = new Rpc::TcpClient(HOST,PORT);
//	Sender->Connect();
//	Sender->Send(quryString);
//	Sender->Recv(rpseString);
	Value value;
	read.parse(rpseString,value);
//	rpseString = value["result"];
	return rpseString;
}
string Adapter::getAdapterName()
{
	return adapterName;
}


Creator::Creator(){
	
}


bool Connector::baseMethod(const Value& root, Value& response)
{
//	response["jsonrpc"] = JSONRPC_VERSION; response["id"] = STD_ID;
//	response["result"] = "Network has received the message.";
	return true;
}

Network::Network()
{
    
}

bool Network::Init()
{
//	networking::init();
//	pthread_t serverThread;
//	pthread_create(&serverThread,NULL,this->ManagerThread,NULL);
//	pthread_join(serverThread,NULL);
//	networking::cleanup();
}

bool Network::Call()
{
//	pthread_t clientThread;
//	pthread_create(&clientThread,NULL,this->SubjectThread,NULL);
}

void* Network::ManagerThread(void* stdParam)
{
    /* Connector Conn;
	Rpc::TcpServer* Mngr = new Rpc::TcpServer(HOST,PORT);
	Mngr->AddMethod(new Rpc::RpcMethod<Connector>(Conn,
			&Connector::baseMethod,string("base_method")));
	Mngr->Bind();
	Mngr->Listen();
	while(1){ Mngr->WaitMessage(1000); }
	pthread_exit(Mngr);*/
}

void* Network::SubjectThread(void* msgParam)
{	
	Message* Msg = (Message*)msgParam;
//	Rpc::TcpClient* Subj = new Rpc::TcpClient(HOST,PORT);
	string queryString = string(Msg->queryMsg);
	string responseString;
//	Subj->Connect();
//	Subj->Send(queryString);
//	Subj->Recv(responseString);
	strcpy(Msg->repseMsg,responseString.c_str());
	msgParam = Msg;
	pthread_exit(NULL);
}

Client::Client(bool stat) {
    status = stat;
}

void Client::connectServer()
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

void Client::parseJson(const char* name)
{
    std::ifstream stream;
    stream.open("elements.json",ifstream::in);
    std::string line,buffer;
    if(stream.is_open()){
        while(stream.good()){
            getline(stream,line);
            buffer.append(line);
        }
        stream.close();
    }
    /*JSONNODE* node = json_parse_unformatted(buffer.c_str());
    JSONNODE_ITERATOR i = json_begin(node);
    while(i != json_end(node)){
        if(i == JSON_NULL) break;
        else if(json_type(*i) == JSON_NODE) continue;
        printf("%s",json_name(*i)); i++;
    }*/
}

Reader::Reader()
{

}

void Reader::parse(std::string str,Value &val)
{

}

FastWriter::FastWriter()
{

}

std::string FastWriter::write(Value &val)
{

}

Player::Player()
{
  
}

