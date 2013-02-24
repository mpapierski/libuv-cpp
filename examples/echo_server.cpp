#include <iostream>
#include <uv++.hpp>

static uv::event_loop default_loop;

int
main()
{
	uv::server echo_server(default_loop);
	echo_server.listen([]() {
		std::cout << "Echo server is listening." << std::endl;
	});
	default_loop.run();
}