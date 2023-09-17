#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (front == nullptr) {
            return -1;
        }

        int item = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }

        return item;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    int k, n;
    cin >> k >> n;

    vector<Queue> queues(k);

    for (int i = 0; i < n; ++i) {
        int item, qn;
        cin >> item >> qn;
        queues[qn].enqueue(item);
    }

    for (int i = 0; i < k; ++i) {
        cout << "Queue " << i << ": ";
        while (!queues[i].isEmpty()) {
            int item = queues[i].dequeue();
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}
