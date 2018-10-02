#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "queryfile.h"

// via https://stackoverflow.com/a/2072890/6782
inline bool ends_with(std::string const & value, std::string const & ending)
{
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cerr << "usage: dnscvt <txtfile>" << std::endl;
		return EXIT_FAILURE;
	}

	try {
		QueryFile	qf;

		// remove .txt extension if found
		std::string input(argv[1]);
		if (ends_with(input, ".txt")) {
			input.erase(input.length() - 4);
		}

		// append .raw
		std::string output = input + ".raw";

		// start the conversion
		qf.read_txt(input);
		qf.write_raw(output);

	} catch (std::runtime_error& e) {
		std::cerr << "error: " << e.what() << std::endl;
	}
}
