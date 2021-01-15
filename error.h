#pragma once
#include <string>
#include <string_view>

namespace ErrorHandling
{
    class Error
    {
        int priority;
        std::string_view message;

    public:
        Error(int priority, std::string_view message);

        [[nodiscard]] int getPriority() const;
        [[nodiscard]] std::string_view getMessage() const;
    };

    bool operator<(const Error &, const Error &);
} // namespace ErrorHandling