#include <iostream>
#include <deque>

int main() {
    std::deque<int> stockPrices;

    int price;
    while (true) {
        std::cin >> price;
        if (price == -1) {
            break;
        }
        stockPrices.push_back(price);
    }

    if (stockPrices.empty()) {
        std::cout << "Deque is empty." << std::endl;
    } else {
        int minPrice = stockPrices.front();

        for (int p : stockPrices) {
            if (p < minPrice) {
                minPrice = p;
            }
        }

        std::cout << minPrice << std::endl;
    }

    return 0;
}
