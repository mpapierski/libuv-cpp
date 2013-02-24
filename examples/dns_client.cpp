#include <iostream>
#include <string>
#include <uv++.hpp>

int
main(int argc, char * argv[])
{
	if (argc < 2)
	{
		return 1;
	}
	uv::event_loop loop;
	for (int i = 1; i < argc; i++)
	{
		uv::getaddrinfo(loop, argv[i], [&loop](std::string const & address) {
			if (address.empty()) {
				std::cerr << loop.last_error() << std::endl;
				return;
			}
			std::cout << address << std::endl;
		});
	}
	loop.run();
	return 0;
}