#if !defined(UVPLUSPLUS_NETWORK_H_)
#define UVPLUSPLUS_NETWORK_H_

namespace uv {

class server;

/**
 * Create new IPv4 address.
 */
class ip4_address
{
private:
	struct sockaddr_in bind_addr_;
	friend class server;
public:
	ip4_address(std::string const & address, unsigned short port);
};

class server
{
private:
	event_loop loop_;
	uv_tcp_t server_;
public:
	server(event_loop const & ev);
	void listen(ip4_address addr, std::function<void()> callback = std::function<void()>());
	static void on_new_connection(uv_stream_t *server, int status);
};

}

#endif /* UVPLUSPLUS_NETWORK_H_ */