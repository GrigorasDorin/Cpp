#include <string>

class Message
{
    std::string message;

public:
    explicit Message(const std::string &message);
    std::string getMessage() const;
};