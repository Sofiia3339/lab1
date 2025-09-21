#include "Functional_Object.h"

Functional_Object::Functional_Object(pair<double, double>& x0, vector<pair<double,double>>& arrb) {
    this->x0 = x0;
    this->arrb = arrb;
    if (arrb.empty()) {
        throw invalid_argument("Input array cannot be empty.");
    }
}

Functional_Object::~Functional_Object() {}

pair<double,double> Functional_Object::getX(){
    return x0;
}

pair<double,double> Functional_Object::operator()()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, arrb.size()-1);
    int rnd = distrib(gen);
    pair<double,double> y;
    if (count == 0) {
        y = x0;
    }
    else {
        y = make_pair((x0.first+arrb[rnd].first)/2, (x0.second + arrb[rnd].second) / 2);
        x0 = y;
    }
    count++;
    return y;
}