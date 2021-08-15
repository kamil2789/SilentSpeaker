#pragma once
#include <thread>
#include <vector>
#include "IServer.h"
#include "asio.hpp"

class AsioServer : public IServer
{
public:
    AsioServer(uint16_t port);
    bool start() override;
    bool stop() override;
private:
    asio::io_context context;
    asio::ip::tcp::acceptor acceptor;
    std::thread threadContext;
    bool isServerRunning;

    void listening();
    static void connectionAttempt(std::error_code ec, asio::ip::tcp::socket socket);
};