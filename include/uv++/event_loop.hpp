#if !defined(UVPLUSPLUS_EVENT_LOOP_H_)
#define UVPLUSPLUS_EVENT_LOOP_H_

#include <cassert>
#include <string>
#include <memory>
#include <new>
#include <uv.h>

namespace uv {

/**
 * Event loop wrapper.
 */
class event_loop
{
private:
	typedef std::shared_ptr<uv_loop_t> pointer_type;
	pointer_type loop_;
public:
	/**
	 * Construct new event loop.
	 */
	event_loop() throw(std::bad_alloc);
	/**
	 * Run event loop.
	 * @param mode Set to UV_RUN_DEFAULT, UV_RUN_ONCE, or UV_RUN_NOWAIT.
	 */
	void run(uv_run_mode mode = UV_RUN_DEFAULT) throw();
	/**
	 * Get native handler
	 */
	pointer_type pointer() const
	{
		return loop_;
	}
	/**
	 * Get last error as std::string.
	 */
	std::string last_error() const;
};

}

#endif /* UVPLUSPLUS_EVENT_LOOP_H_ */