#include "file_reader.h"
#include "runner.h"
#include "libs/zmq.hpp"


int main()
{
	runner r = runner();
	display_run_result(r.run_command("ls -la"));

	file_reader fr = file_reader("/proc/stat");

	fr.read_file();
	fr.display();

	return 0;
}
