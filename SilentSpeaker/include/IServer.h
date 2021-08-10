#pragma once

class IServer
{
public:
    virtual bool start() = 0;
    virtual bool stop() = 0;
};