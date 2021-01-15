#pragma once
#include <vector>
#include <utility>

template <typename T>
class Grid
{
private:
    int height;
    int width;
    std::vector<std::vector<T>> grid;

public:
    explicit Grid(int height = 3, int width = 3) : height{height}, width{width}, grid(height, std::vector<T>(width)) {}

    [[nodiscard]] T at(int x, int y) const
    {
        return grid[x][y];
    }

    void set(std::pair<int, int> position, const T &value)
    {
        grid[position.first][position.second] = value;
    }
};