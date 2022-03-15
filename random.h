#pragma once

#include <random>

class RandGenerator {
    std::random_device rd; 
    std::mt19937 gen; 
    std::uniform_int_distribution<int> distr;
public:
    RandGenerator()
        : gen(rd())
        , distr(2, 12)
    {}

    int generate() {
        return distr(gen);
    }
};