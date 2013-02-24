CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
PROJECT (examples)

ADD_EXECUTABLE (dns_client
	dns_client.cpp)
TARGET_LINK_LIBRARIES (dns_client
	uv++)

ADD_EXECUTABLE (echo_server
	echo_server.cpp)
TARGET_LINK_LIBRARIES (echo_server
	uv++)
