#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include <stdexcept>

class Functional_Object {
private:
    std::pair<double, double> x0;
    std::vector<std::pair<double, double>> arrb;
    int count = 0;

public:
    Functional_Object(std::pair<double, double>& x0, std::vector<std::pair<double,double>>& arrb);
    ~Functional_Object() = default;

    std::pair<double, double> getX();
    std::pair<double, double> operator()();
};

