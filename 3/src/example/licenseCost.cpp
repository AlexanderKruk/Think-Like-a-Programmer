#include <iostream>

int main() {
    double grossSales = 1000000;
    const int NUM_CATEGORIES = 4;
    const double categoryThresholds[NUM_CATEGORIES] = 
        {0.0, 50000.0, 150000.0, 500000.0};
    const double licenseCost[NUM_CATEGORIES] = 
        {50.0, 200.0, 1000.0, 5000.0};
    int category = 0;
    while (category < NUM_CATEGORIES && categoryThresholds[category] <=
    grossSales) {
        category++;
    }
    int cost = licenseCost[category - 1];
    std::cout << cost;
}