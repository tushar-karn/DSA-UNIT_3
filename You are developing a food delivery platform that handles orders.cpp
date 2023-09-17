#include <iostream>

struct OrderNode {
    int order;
    OrderNode* next;
    OrderNode(int order) : order(order), next(nullptr) {}
};

class OrderQueue {
private:
    OrderNode* front;

public:
    OrderQueue() : front(nullptr) {}

    void insertOrder(int order) {
        OrderNode* newNode = new OrderNode(order);
        if (!front) {
            front = newNode;
        } else {
            OrderNode* current = front;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    static bool areQueuesEqual(const OrderQueue& queue1, const OrderQueue& queue2) {
        OrderNode* current1 = queue1.front;
        OrderNode* current2 = queue2.front;

        while (current1 && current2) {
            if (current1->order != current2->order) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }

        return !current1 && !current2;
    }
};

int main() {
    OrderQueue queue1, queue2;

    int N1, N2;
    std::cin >> N1;
    for (int i = 0; i < N1; ++i) {
        int order;
        std::cin >> order;
        queue1.insertOrder(order);
    }

    std::cin >> N2;
    for (int i = 0; i < N2; ++i) {
        int order;
        std::cin >> order;
        queue2.insertOrder(order);
    }

    if (OrderQueue::areQueuesEqual(queue1, queue2)) {
        std::cout << "The queues have the same elements in the same order." << std::endl;
    } else {
        std::cout << "The queues do not have the same elements in the same order." << std::endl;
    }

    return 0;
}
