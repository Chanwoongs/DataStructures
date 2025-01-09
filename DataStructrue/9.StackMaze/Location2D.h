#pragma once

class Location2D
{
public:
    Location2D() {}
    Location2D(int row, int column)
        : row(row), column(column)
    {
    }

public:
    int row = 0;
    int column = 0;
};