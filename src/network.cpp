#include <uv++.hpp>

uv::ip4_address::ip4_address(std::string const & address, unsigned short port)
	: bind_addr_(::uv_ip4_addr(address.c_str(), port))
{

}

void uv::server::on_new_connection(uv_stream_t *server, int status) {
    if (status == -1) {
        // error!
        return;
    }
    uv::server * _this = static_cast<uv::server *>(server->data);
    uv_tcp_t *client = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
    uv_tcp_init(_this->loop_.pointer().get(), client);
    /*if (uv_accept(server, (uv_stream_t*) client) == 0) {
        uv_read_start((uv_stream_t*) client, alloc_buffer, echo_read);
    }
    else {
        uv_close((uv_handle_t*) client, NULL);
    }*/
}

uv::server::server(uv::event_loop const & ev)
	: loop_(ev)
{
	::uv_tcp_init(loop_.pointer().get(), &server_);
	server_.data = this;
}

void uv::server::listen(ip4_address addr, std::function<void()> callback)
{
	::uv_tcp_bind(&server_, addr.bind_addr_);
	int r = ::uv_listen((uv_stream_t*)&server_, 128, &on_new_connection);
	if (!r) {
		throw std::runtime_error(loop_.last_error());
	}
}