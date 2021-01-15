#include "error_corelation.h"
#include <stdexcept>

namespace ErrorHandling
{
    void ErrorCorelation::addError(const Error &e)
    {
        errors.emplace(e);
    }

    Error ErrorCorelation::getHighestError()
    {
        if (errors.empty())
        {
            throw std::out_of_range{"No more erros!"};
        }

        auto e = errors.top();
        errors.pop();

        return e;
    }
} // namespace ErrorHandling