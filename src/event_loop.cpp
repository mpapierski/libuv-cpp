#include <uv++/event_loop.hpp>

uv::event_loop::event_loop() throw(std::bad_alloc)
	: loop_(uv_loop_new(), &::uv_loop_delete)
{
	if (!loop_)
	{
		throw std::bad_alloc();
	}
}

void uv::event_loop::run(uv_run_mode mode) throw()
{
	assert(loop_ && "Unable to run event loop.");
	::uv_run(loop_.get(), mode);
}

std::string uv::event_loop::last_error() const
{
	return ::uv_err_name(::uv_last_error(this->loop_.get()));
}
