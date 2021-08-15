#pragma once
#include <vector>
#include <cstdint>
#include <string>

enum class MessageHeader
{
    Info
};

class Message
{
public:
    Message(MessageHeader header);
    size_t getSize() const;
    void append(const std::vector<uint8_t>& data);
    void append(const std::string& data);
    //FUTURE IMPROVMENT - RETURN REFERENCE, DO NOT EXTRA COPY
    std::string readMessage(size_t sizeToRead = 0) const;
private:
    MessageHeader header;
    std::vector<uint8_t> body;
};