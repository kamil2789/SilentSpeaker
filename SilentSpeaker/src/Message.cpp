#include <vector>
#include <cstdint>
#include <string>
#include "Message.h"

Message::Message(MessageHeader header):
    header{header}
{}

size_t Message::getSize() const
{
    return body.size();
}

void Message::append(const std::vector<uint8_t>& data)
{
    body.insert(body.end(), data.begin(), data.end());
}

void Message::append(const std::string& data)
{
    body.insert(body.end(), data.begin(), data.end());
}

std::string Message::readMessage(size_t sizeToRead) const
{
    if (sizeToRead == 0 || sizeToRead > body.size())
    {
        return std::string{body.begin(), body.end()};
    }
    else
    {
        return std::string{body.begin(), body.begin() + sizeToRead};
    }
}