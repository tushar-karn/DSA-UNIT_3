#include <iostream>
#include <queue>
#include <string>

int main() {
    int max_capacity, num_packets;
    std::cin >> max_capacity >> num_packets;

    auto cmp = [](std::pair<int, std::string> left, std::pair<int, std::string> right) {
        return left.first > right.first;
    };

    std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, decltype(cmp)> pq(cmp);

    std::cout << "Processing packets based on priority:" << std::endl;

    for (int i = 0; i < num_packets; ++i) {
        int priority;
        std::cin >> priority;
        std::string data;
        std::cin.ignore(); // Ignore the newline character
        std::getline(std::cin, data);
        pq.push({priority, data});
    }

    while (!pq.empty()) {
        int priority = pq.top().first;
        std::string data = pq.top().second;
        pq.pop();
        std::cout << "Processing packet with priority " << priority << " and data: " << data << std::endl;
    }

    return 0;
}
