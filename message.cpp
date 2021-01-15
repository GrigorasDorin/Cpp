#include "message.h"

Message::Message(const std::string &message)
    : message{message} {}

std::string Message::getMessage() const
{
     return message;
}