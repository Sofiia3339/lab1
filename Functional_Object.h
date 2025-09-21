 #pragma once
#include <iostream>
#include <vector>
#include <random>
#include <utility>
using namespace std;

class Functional_Object {
private:
    pair<double, double> x0;
    vector<pair<double,double>> arrb;
    int count = 0;

public:
    Functional_Object(pair<double, double>& x0, vector<pair<double,double>>& arrb);
    ~Functional_Object() = default;

    pair<double, double> getX();
    pair<double, double> operator()();
};

