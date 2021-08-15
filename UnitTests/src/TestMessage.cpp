#include <vector>
#include "Message.h"
#include "gtest\gtest.h"

TEST(Message, appendMessage_UseString_ReturnValidSize)
{
    const std::string exampleData{"ExampleData410/nxa21#$%"};
    Message message{MessageHeader::Info};

    ASSERT_EQ(0, message.getSize());
    message.append(exampleData);

    ASSERT_EQ(exampleData.size(), message.getSize());
}

TEST(Message, appendMessage_UseChars_ReturnValidSize)
{
    const std::string exampleData{"ExampleData410/nxa21#$%"};
    std::vector<uint8_t> exampleByteData(exampleData.begin(), exampleData.end());

    Message message{MessageHeader::Info};

    ASSERT_EQ(0, message.getSize());
    message.append(exampleByteData);

    ASSERT_EQ(exampleByteData.size(), message.getSize());
}

TEST(Message, readMessage_UseString_ReturnValidString)
{
    const std::string exampleData{"ExampleData410/nxa21#$%"};
    const std::string exampleSecondData{" fg ubf\ng43 5# &$5y4 tg$%"};
    Message message{MessageHeader::Info};

    message.append(exampleData);
    ASSERT_EQ(exampleData.size(), message.getSize());
    ASSERT_EQ(exampleData, message.readMessage());

    message.append(exampleSecondData);
    ASSERT_EQ(exampleData.size() + exampleSecondData.size(), message.getSize());
    ASSERT_EQ(exampleData + exampleSecondData, message.readMessage());
}


TEST(Message, readMessage_UseChars_ReturnValidString)
{
    const std::string exampleData{"ExampleData410/nxa21#$%"};
    const std::string exampleSecondData{" fg ubf\ng43 5# &$5y4 tg$%"};
    std::vector<uint8_t> exampleByteData(exampleData.begin(), exampleData.end());
    std::vector<uint8_t> exampleSecondByteData(exampleSecondData.begin(), exampleSecondData.end());

    Message message{MessageHeader::Info};

    message.append(exampleByteData);
    ASSERT_EQ(exampleByteData.size(), message.getSize());
    ASSERT_EQ(exampleData, message.readMessage());

    message.append(exampleSecondByteData);
    ASSERT_EQ(exampleByteData.size() + exampleSecondByteData.size(), message.getSize());
    ASSERT_EQ(exampleData + exampleSecondData, message.readMessage());
}