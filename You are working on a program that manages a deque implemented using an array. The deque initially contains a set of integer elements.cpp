#include <iostream>
#include <deque>

int main() {
    int N;
    std::cin >> N;
    
    std::deque<int> myDeque;
    
    for (int i = 0; i < N; ++i) {
        int element;
        std::cin >> element;
        myDeque.push_back(element);
    }
    
    while (!myDeque.empty()) {
        std::cout << myDeque.back() << " ";
        myDeque.pop_back();
    }
    
    std::cout << std::endl;

    return 0;
}
