#include "error.h"

namespace ErrorHandling
{
    bool operator<(const Error &e1, const Error &e2)
    {
        return e1.getPriority() < e2.getPriority();
    }

    Error::Error(int priority, std::string_view message) : priority{priority}, message{message} {}

    int Error::getPriority() const
    {
        return priority;
    }

    std::string_view Error::getMessage() const
    {
        return message;
    }

} // namespace ErrorHandling