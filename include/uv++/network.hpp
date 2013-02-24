#if !defined(UVPLUSPLUS_NETWORK_H_)
#define UVPLUSPLUS_NETWORK_H_

namespace uv {

/**
 * Create new IPv4 address.
 */
class ip4_address
{
private:
	struct sockaddr_in bind_addr_;
public:
	ip4_address(std::string const & address, unsigned short port);
};

struct server
{
	event_loop loop_;
	server(event_loop ev);
	void listen(std::function<void()> callback = std::function<void()>());
};

}

#endif /* UVPLUSPLUS_NETWORK_H_ */