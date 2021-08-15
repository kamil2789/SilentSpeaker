#include <iostream>
#include "AsioServer.h"

AsioServer::AsioServer(uint16_t port):
    acceptor(context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))
{}

bool AsioServer::start()
{
    if (isServerRunning)
    {
        std::cout<<"Server is already started. Nothing to do" << std::endl;
        return true;
    }

	try
	{
		listening();
		threadContext = std::thread([this](){ context.run(); });
	}
	catch (std::exception& e)
	{
		std::cerr << "Server cannot be started: " << e.what() << std::endl;
		return false;
	}

	std::cout << "Server started" << std::endl;
    isServerRunning = true;
	return true;
}

bool AsioServer::stop()
{
    return true;
}

void AsioServer::connectionAttempt(std::error_code ec, asio::ip::tcp::socket socket)
{
	if (!ec)
	{
		std::cout << "Server: new connection from: " << socket.remote_endpoint() << std::endl;
		
	}
}

void AsioServer::listening()
{
    acceptor.async_accept(AsioServer::connectionAttempt);
}