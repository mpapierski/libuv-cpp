#if !defined(UVPLUSPLUS_DNS_H_)
#define UVPLUSPLUS_DNS_H_

#include <string>
#include <functional>
#include <stdexcept>
#include <memory>
#include <vector>
#include <uv++/event_loop.hpp>

namespace uv {
	/**
	 * Get address info.
	 * @param loop Event loop to use.
	 * @param address Address to query.
	 * @param callback Callback of type void(std::string const &).
	 *                 First parameter is an IP address.
	 */
	void getaddrinfo(uv::event_loop const & loop, std::string const & address,
		std::function<void(std::string const &)> callback);
}

#endif /* UVPLUSPLUS_DNS_H_ */