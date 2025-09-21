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

int main() {
    int n;
    pair<double, double>x;
    vector<pair<double,double>> numbers;
    readFromFile(n, x, numbers);
    Functional_Object obj = Functional_Object(x, numbers);
    ofstream file("output.txt");
    if (!file) {
        cout << "Unable to open file output.txt" << endl;
    }
    else {
        file << n << endl;
        file << obj.getX().first << " " << obj.getX().second << endl;
        pair<double, double> y;
        for (int i = 0; i < n; i++) {
            y = obj();
            file << y.first << " " << y.second << endl;
        }
        file.close();
        cout << "Closed sucsesfully" << endl;
    }
}