#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>


enum {
	MAX_BUFFER = 128
};

struct run_result 
{
	std::string command;
	std::string output;
	int return_code;
};

void display_run_result(run_result result);


class runner
{
	public:
		runner();
		~runner();
		run_result run_command(std::string command);
		
};

