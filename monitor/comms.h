#pragma once

#include "file_reader.h"
#include "runner.h"
#include "libs/zmq.hpp"

class comms_module 
{
	protected:
		std::string bind_address;
		zmq::context_t* ctx;
		zmq::socket_t* socket;
	public:
		comms_module(std::string address, int num_theads, int socket_type): bind_address(address)
		{
			ctx = new zmq::context_t(num_theads);
			socket = new zmq::socket_t(*ctx, socket_type);
		}
		std::string get_address() { return bind_address;}
};


class client_module: public comms_module
{
	public:
		client_module(std::string address);
		bool setup();
		void send_message(std::string message);
		void receive_message();
};


class server_module: public comms_module
{
	public:
		server_module(std::string address);
		bool setup();
		void send_message(std::string message);
		void receive_message();

};


