#pragma once

#include "comms.h"
#include <unistd.h>


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
	zmq::message_t response (4);
	memcpy ((void *) response.data (), "done", 4);
	socket->send (response);
	std::cout << "sent response" << std::endl;
}

void client_module::receive_message()
{
	while (true)
	{
		zmq::message_t request;
		socket->recv(&request);
		std::string message = std::string(static_cast<char*>(request.data()), request.size());
		std::cout << "received message: " << message << std::endl;
		sleep(10);
		this->send_message("I did get stuff");
	}
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
	while (true)
	{
		zmq::message_t request (28);
		memcpy ((void *) request.data (), "I want to get some breakfast", 28);
		socket->send (request);
		std::cout << "message sent waiting for reply" << std::endl;
		this->receive_message();
	}
}

void server_module::receive_message()
{
	zmq::message_t response;
	socket->recv(&response);
	std::string message = std::string(static_cast<char*>(response.data()), response.size());
	std::cout << "received message: " << message << std::endl;
}

