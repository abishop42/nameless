#pragma once

#include "comms.h"


client_module::client_module(std::string address): comms_module(address, 1, ZMQ_REP)
{
	
}

bool client_module::setup()
{
	bool result = true;
	std::cout << "seting up client module on " << this->get_address() << std::endl;
	socket->connect(bind_address.c_str());

	return result;
}

void client_module::send_message(std::string message)
{

}

void client_module::receive_message()
{

}

server_module::server_module(std::string address) : comms_module(address, 1, ZMQ_REQ)
{
}


bool server_module::setup()
{
	bool result = false;
	std::cout << "seting up server module on " << this->get_address() << std::endl;
	socket->bind(bind_address.c_str());
	return result;
}

void server_module::send_message(std::string message)
{

}

void server_module::receive_message()
{

}

