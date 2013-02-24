#include <uv++.hpp>

uv::ip4_address::ip4_address(std::string const & address, unsigned short port)
	: bind_addr_(::uv_ip4_addr(address.c_str(), port))
{

}

uv::server::server(uv::event_loop ev)
	: loop_(ev)
{
}

void uv::server::listen(std::function<void()> callback)
{

}