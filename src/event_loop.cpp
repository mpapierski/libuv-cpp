#include <uv++/event_loop.hpp>

using namespace uv;

event_loop::event_loop() throw(std::bad_alloc)
	: loop_(uv_loop_new(), destructor())
{
	if (!loop_)
	{
		throw std::bad_alloc();
	}
}

void event_loop::run(uv_run_mode mode) throw()
{
	assert(loop_ && "Unable to run event loop.");
	::uv_run(loop_.get(), mode);
}