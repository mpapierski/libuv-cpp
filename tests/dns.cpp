#include <iostream>
#include <string>
#include <uv++/event_loop.hpp>
#include <uv++/dns.hpp>

static uv::event_loop loop;

int
main()
{
	for (int i = 1; i <= 10; i++)
	{
		uv::getaddrinfo(loop, "google.pl", [i](std::string const & address) {
			std::cout << i << ". got result: " << address << std::endl;
		});
	}
	uv::getaddrinfo(loop, "", [](std::string const & address) {
		if (address.empty()) {
			std::cout << "OK" << std::endl;
		}
	});
	loop.run();
}