#include "Functional_Object.h"

Functional_Object::Functional_Object(pair<double, double>& x0, vector<pair<double,double>>& arrb) {
    this->x0 = x0;
    this->arrb = arrb;
}

Functional_Object::~Functional_Object()
{
}

pair<double,double> Functional_Object::getX()
{
    return x0;
}