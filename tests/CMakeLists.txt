CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
PROJECT (tests)

ADD_EXECUTABLE (event_loop
	event_loop.cpp)
TARGET_LINK_LIBRARIES (event_loop
	uv++)

ADD_EXECUTABLE (dns
	dns.cpp)
TARGET_LINK_LIBRARIES (dns
	uv++)

ADD_TEST(event_loop event_loop)
ADD_TEST(dns dns)