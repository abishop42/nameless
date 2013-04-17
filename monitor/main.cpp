#include "comms.h"

void display_args(int argc, char* argv[])
{
	for (int i = 0; i < argc; i++)
	{
		std::cout << "arg " << i << " = " << argv[i] << std::endl;
	}
}

int main(int argc, char* argv[])
{
	
	display_args(argc, argv);

	std::string client_address = "tcp://localhost:5555";
	std::string server_address = "tcp://*:5555";



	if (strcmp(argv[1], "server") == 0)
	{
		std::cout << "server will be built" << std::endl;
		server_module server = server_module(server_address);
		server.setup();
	}
	else if (strcmp(argv[1],"client") == 0)
	{
		std::cout << "client will be built" << std::endl;
		client_module client = client_module(client_address);
		client.setup();
	}
	else
	{
		std::cout << "not going to do anything due to args passed in" << std::endl;
	}

	return 0;
}
