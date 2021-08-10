#include "Message.h"

Message::Message(MessageHeader header):
    header{header}
{}

size_t Message::getSize() const
{
    return body.size();
}

void Message::append(const std::vector<std::byte>& data)
{
    body.insert(body.end(), data.begin(), data.end());
}

void Message::append(const std::string& data)
{
    body.insert(body.end(), data.begin(), data.end());
}