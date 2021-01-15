#pragma once
#include <queue>
#include "error.h"

namespace ErrorHandling
{
    class ErrorCorelation
    {
        std::priority_queue<Error> errors;
    public:
        void addError(const Error &);
        [[nodiscard]] Error getHighestError();
    };
} // namespace ErrorHandling