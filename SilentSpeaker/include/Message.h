#pragma once
#include <vector>
#include <cstddef>
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
    void append(const std::vector<std::byte>& data);
    void append(const std::string& data);
private:
    MessageHeader header;
    std::vector<std::byte> body;
};