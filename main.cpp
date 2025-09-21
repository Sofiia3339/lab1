// Clang (C++20)

#include "Functional_Object.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <stdexcept>

void readFromFile(int& n, std::pair<double, double>& x, std::vector<std::pair<double, double>>& numbers) {
    std::ifstream file("input.txt");
    if (!file) {
        throw std::runtime_error("Unable to open input.txt");
    }

    if (!(file >> n >> x.first >> x.second)) {
        throw std::runtime_error("Invalid format in input.txt");
    }

    std::pair<double, double> num;
    while (file >> num.first >> num.second) {
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        throw std::runtime_error("No base points found in input.txt");
    }
}

int main() {
    try {
        int n;
        std::pair<double, double> x;
        std::vector<std::pair<double, double>> numbers;

        readFromFile(n, x, numbers);

        Functional_Object obj(x, numbers);

        std::ofstream file("output.txt");
        if (!file) {
            throw std::runtime_error("Unable to open output.txt");
        }

        file << obj.getX().first << " " << obj.getX().second << std::endl;
        for (int i = 1; i < n; i++) {
            auto y = obj();
            file << y.first << " " << y.second << std::endl;
        }

        std::cout << "Program completed successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}