#if !defined(UVPLUSPLUS_EVENT_LOOP_H_)
#define UVPLUSPLUS_EVENT_LOOP_H_

#include <cassert>
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
	struct destructor
	{
		void operator()(uv_loop_t * p) const
		{
			assert(p);
			::uv_loop_delete(p);
		}
	};
	std::unique_ptr<uv_loop_t, destructor> loop_;
public:
	event_loop() throw(std::bad_alloc);
	/**
	 * Run event loop.
	 * @param mode Set to UV_RUN_DEFAULT, UV_RUN_ONCE, or UV_RUN_NOWAIT.
	 */
	void run(uv_run_mode mode = UV_RUN_DEFAULT) throw();
};

}

#endif /* UVPLUSPLUS_EVENT_LOOP_H_ */