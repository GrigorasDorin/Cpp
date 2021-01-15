#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <optional>
#include <cstring>
#include <array>
#include <list>

#include "error_corelation.h"
#include "message.h"
#include "grid.h"
#include "board.h"

using namespace std;
using namespace ErrorHandling;

struct Persona
{
    size_t id;
    string name;
};

void RemoveOddIds()
{
    vector<Persona> arr{Persona{1, "Drn"}, Persona{2, "Drn"}, Persona{3, "Drn"}, Persona{4, "Drn"}};

    auto it = remove_if(begin(arr), end(arr), [](const Persona &elem) { return elem.id % 2 == 1; });
    arr.erase(it, end(arr));

    for_each(begin(arr), end(arr), [](const Persona &elem) { cout << elem.id << endl; });
}

template <typename T>
[[nodiscard]] optional<size_t> Find(T const &value, T const *arr, size_t const size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return optional<size_t>{i};
        }
    }

    return optional<size_t>{};
}

template <>
[[nodiscard]] optional<size_t> Find(char const &value, char const *arr, size_t const size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(arr + i, &value) == 0)
        {
            return optional<size_t>{i};
        }
    }

    return optional<size_t>{};
}

int main()
{
    Message message{"Hello, Dorin"};
    cout << message.getMessage() << endl;
    RemoveOddIds();

    cout << endl;

    Grid<int> grid{};
    cout << grid.at(1, 2) << endl;

    Board<int> board{4, 5};
    board.set({1, 2}, 100);
    board.set({3, 3}, 75);
    board.move({1, 2}, {3, 3});

    optional<size_t> index{};
    int intArr[]{1, 2, 3};
    index = Find(3, intArr, 6);
    index = Find<int>(3, intArr, 6);

    cout << (index.has_value() ? "Found it" : "Doesn't exist!") << endl;

    double doubleArr[]{};
    index = Find(3.0, doubleArr, 6);
    index = Find<double>(3.0, doubleArr, 6);

    list<int> seq{1, 2, 3};
    auto it = begin(seq);
    ++it;
    --it;
    //it += 3;  // Not permitted

    list<string> dictionary{"ascuns", "anemic"};
    list<string> bWords{"baston", "bacanie"};

    auto st = cbegin(dictionary);
    dictionary.splice(st, bWords);

    cout << bWords.empty() ? "Empty" : "It still has words...";

    array<int, 2> arr1{1, 2};
    get<1>(arr1);
    priority_queue<int> pQueue{};

    ErrorCorelation errors{};

    errors.addError({1, "Easy"});
    errors.addError({2, "Medium"});
    errors.addError({10, "Hardcore"});
    errors.addError({2, "Medium - Rare"});
    errors.addError({4, "Expert"});

    try
    {
        while (true)
        {
            auto err = errors.getHighestError();
            cout << err.getMessage() << endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << endl;
    }

    return 0;
}