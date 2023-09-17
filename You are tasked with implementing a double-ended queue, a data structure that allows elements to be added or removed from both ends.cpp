#include <iostream>
#include <deque>

int main() {
    std::deque<int> myDeque;

    int front1, front2, back1, back2, front3, back3;

    std::cin >> front1 >> front2 >> back1 >> back2 >> front3 >> back3;

    myDeque.push_front(front1);
    myDeque.push_front(front2);
    myDeque.push_back(back1);
    myDeque.push_back(back2);
    myDeque.push_front(front3);
    myDeque.push_back(back3);

    for (int element : myDeque) {
        std::cout << element << " ";
    }
    
    std::cout << std::endl;

    return 0;
}
