#include <iostream>

int compareFunc(const void * voidA, const void * voidB);

const int NUM_AGENTS = 3;
const int NUM_MONTHS = 12;
int sales[NUM_AGENTS][NUM_MONTHS] = {
    {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
    {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
    {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
};

int main() {
    int middle = 0;
    int curmiddle = 0;
    int middleAgent = 0;
    for (int i = 0; i < NUM_AGENTS; i++){
        qsort(sales[i], NUM_MONTHS, sizeof(int), compareFunc);
    }
        for(int agent = 0; agent < NUM_AGENTS; agent++) {
            for(int month = 0; month < NUM_MONTHS; month++) {
                std::cout << sales[agent][month] << " ";
        }
        std::cout  << "\n";
    }
    for(int agent = 0; agent < NUM_AGENTS; agent++) {
        if (NUM_MONTHS % 2 == 0)
            curmiddle = (sales[agent][NUM_MONTHS / 2 - 1] + sales[agent][(NUM_MONTHS / 2)]) / 2;
        else
            curmiddle = sales[agent][NUM_MONTHS / 2 - 1]; 
        std::cout << "agent " << agent + 1 << " middle :" << curmiddle << "\n";
        if (middle < curmiddle) {
            middle = curmiddle;
            middleAgent = agent + 1;
        }
    }
    std::cout << "agent with Biggest Middle: " << middleAgent;

}

int compareFunc(const void * voidA, const void * voidB) {
    int * intA = (int *)(voidA);
    int * intB = (int *)(voidB);
    return *intA - *intB;
}