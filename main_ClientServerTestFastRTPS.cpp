#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <cstdint>
#include <sstream>

#include "EprosimaServer.h"
#include "EprosimaClientTest.h"

using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;
using std::cout;
using std::endl;

#if defined(_WIN32)
#define COPYSTR strcpy_s
#else
#define COPYSTR strcpy
#endif

enum E_SIDE
{
	CLIENT,
	SERVER
};


int main(int argc, char** argv) {
	cout << "Starting " << endl;
	E_SIDE side;
	int samples = 10000;
	if (argc > 1)
	{
		if (strcmp(argv[1], "client") == 0)
			side = E_SIDE::CLIENT;
		else if (strcmp(argv[1], "server") == 0)
			side = E_SIDE::SERVER;
		else
		{
			cout << "Argument 1 needs to be client OR server" << endl;
			return 0;
		}
		if (argc > 3)
		{
			std::istringstream iss(argv[3]);
			if (!(iss >> samples))
			{
				cout << "Problem reading samples number,using default 10000 samples " << endl;
				samples = 10000;
			}
		}
	}
	else
	{
		cout << "Client Server Test needs 1 arguments: (client/server)" << endl;
		return 0;
	}

	if (side == E_SIDE::SERVER)
	{
		EprosimaServer server;
		server.init();
		server.serve();
	}
	if (side == E_SIDE::CLIENT)
	{
		EprosimaClientTest clienttest;
		double result = clienttest.run(samples);
		if (result > 0)
			cout << "Mean Time of " << samples << " samples: " << result << " us" << endl;
		else
			cout << "Some problem with the test " << endl;
	}



	cout << "EVERYTHING STOPPED FINE" << endl;

	return 0;
}