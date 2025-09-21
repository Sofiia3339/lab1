#include"Functional_Object.h"
#include<fstream>
using namespace std;

void readFromFile(int& n, pair<double,double>& x, vector<pair<double,double>>& numbers) {
    ifstream file("input.txt");
    if (!file) {
        cout << "Unable to open file input.txt" << endl;
        return;
    }
    file >> n >> x.first >> x.second;
    pair<int,int> num;
    while (file >> num.first >> num.second) {
        numbers.push_back(num);
    }
    file.close();
}

