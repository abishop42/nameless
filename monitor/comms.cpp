#pragma once

#include "comms.h"


client_module::client_module(std::string address): comms_module(address)
{
	
}

bool client_module::setup()
{
	bool result = true;
	std::cout << "seting up client module on " << this->get_address() << std::endl;

	return result;
}

void client_module::send_message(std::string message)
{

}

void client_module::receive_message()
{

}

server_module::server_module(std::string address) : comms_module(address)
{
}


bool server_module::setup()
{
	bool result = false;
	std::cout << "seting up server module on " << this->get_address() << std::endl;
	return result;
}

void server_module::send_message(std::string message)
{

}

void server_module::receive_message()
{

}

