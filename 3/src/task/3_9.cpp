#include <iostream>

const int NUM_AGENTS = 3;
const int NUM_MONTHS = 12;
int sales[NUM_AGENTS][NUM_MONTHS] = {
    {1856, 498, 143, 87478, -1, 2653, -1, 3754, 387587, 4513, 276, 32},
    {5865, 5456, 3983, -1, 9957, 4785, 3875, 3838, -1, 1122, 7766, 2534},
    {23, 55, 67, 99, 265, -1, 232, 223, 4546, -1, 4544, 3434}
};

int main() {
    int highestSales = 0;
    int count = 0;
    int currSale = 0;
    int startStop = 0;
    for(int agent = 0; agent < NUM_AGENTS; agent++) {
        for(int month = 0; month < NUM_MONTHS; month++) {
            if (sales[agent][month] == -1)
                startStop++;
            if (startStop == 1)
            {
                count++;
                currSale += sales[agent][month];
            }
        }
        std::cout << count << ":" << currSale / (count - 1) << "\n";
        if(currSale / (count - 1) > highestSales)
            highestSales = currSale / (count - 1);
        currSale = 0;
        count = 0;
        startStop = 0;
    }
    std::cout << "High: " << highestSales;
}
