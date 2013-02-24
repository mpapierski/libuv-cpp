#include <uv++/dns.hpp>

struct resolve_data
{
	uv::event_loop::weak_pointer_type loop_;
	std::function<void(std::string const &)> callback_;
	::uv_getaddrinfo_t resolver_;
};

/**
 * DNS resolver callback.
 */
static void on_resolved(uv_getaddrinfo_t *resolver, int status, struct addrinfo *res)
{
	std::unique_ptr<resolve_data> data(static_cast<resolve_data *>(resolver->data));
	if ((status == -1) || !res)
	{
		data->callback_(std::string());
		return;
	}
	if (uv::event_loop::pointer_type obj = data->loop_.lock())
	{
		std::vector<char> addr(17, '\0');
		uv_ip4_name((struct sockaddr_in*) res->ai_addr, addr.data(), 16);
		std::string result(addr.begin(), addr.end());
		data->callback_(result);	
	}
}

void uv::getaddrinfo(uv::event_loop const & loop, std::string const & address,
	std::function<void(std::string const &)> callback)
{
	resolve_data * data = new resolve_data;
	data->loop_ = loop.weak();
	data->callback_ = callback;
	data->resolver_.data = data;
	int r = uv_getaddrinfo(loop.native().get(), &data->resolver_, &on_resolved, address.c_str(), 0, 0);
	if (r)
	{
		delete data;
		throw std::runtime_error(loop.last_error());
	}
}
