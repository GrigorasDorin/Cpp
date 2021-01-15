#pragma once
#include <utility>
#include "grid.h"

template <typename T>
class Board : public Grid<T>
{
private:
public:
    Board(int height, int width) : Grid<T>(width, height) {}
    void move(std::pair<int, int> src, std::pair<int, int> dest)
    {
        Grid<T>::set(dest, Grid<T>::at(src.first, src.second));
    }
};