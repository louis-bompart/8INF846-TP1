#pragma once
#include <vector>

class Aspirateur {
public:
    Aspirateur();
    ~Aspirateur();

    void Execute();

    std::vector<int> Position() const
    {
        return position;
    }
    void Position(std::vector<int> val)
    {
        position = val;
    }

private:
    std::vector<int> position;
    std::vector<int[2]> Goals;
};

