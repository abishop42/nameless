#pragma once

#include "file_reader.h"
#include "runner.h"
#include "libs/zmq.hpp"

class comms_module 
{
	private:
		std::string bind_address;
	public:
		comms_module(std::string address): bind_address(address) {}
		std::string get_address() { return bind_address;}
};


class client_module: public comms_module
{
	public:
		client_module(std::string address);
		bool setup();
		void send_message(std::string message);
		void receive_message();

	private:
		zmq::context_t context;
		zmq::socket_t socket;
};


class server_module: public comms_module
{
	public:
		server_module(std::string address);
		bool setup();
		void send_message(std::string message);
		void receive_message();

	//private:
	//	zmq::context_t context;
	//	zmq::socket_t socket;
};


