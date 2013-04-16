#include "runner.h"

void display_run_result(run_result result)
{
	std::cout << "* command     -> " << result.command << std::endl
		  << "* return code -> " << result.return_code << std::endl
		  << "* output " << std::endl 
		  << result.output << std::endl;
}

runner::runner()
{

}


runner::~runner()
{

}


run_result runner::run_command(std::string  command)
{


	char buffer[MAX_BUFFER];
	run_result result;

	result.command = command;
	command += " 2>&1";

	FILE *output = popen((char *)command.c_str(), "r");

	while(fgets(buffer, sizeof(buffer), output)!=NULL)
	{
		result.output += buffer;
	}

	result.return_code = pclose(output);

	return result;

}

