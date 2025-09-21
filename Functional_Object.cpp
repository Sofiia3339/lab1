#include "Functional_Object.h"

Functional_Object::Functional_Object(std::pair<double, double>& x0, std::vector<std::pair<double,double>>& arrb) {
    if (arrb.empty()) {
        throw std::invalid_argument("Input array cannot be empty.");
    }
    this->x0 = x0;
    this->arrb = arrb;
}

std::pair<double,double> Functional_Object::getX(){
    return x0;
}

std::pair<double,double> Functional_Object::operator()()
{
    // Статичні об'єкти, що ініціалізуються один раз
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, arrb.size() - 1);

    std::pair<double,double> y;
    if (count == 0) {
        y = x0;
    } else {
        int rnd = distrib(gen);
        y.first = (x0.first + arrb[rnd].first) / 2;
        y.second = (x0.second + arrb[rnd].second) / 2;
        x0 = y;
    }
    count++;
    return y;
}