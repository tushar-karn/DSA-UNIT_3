// You've been assigned the challenge of developing a queue data structure using a linked list.
// The program should allow users to interact with the queue by enqueuing positive integers and subsequently dequeuing and displaying elements.


#include <iostream>
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

    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
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
            return -1; // Queue is empty
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
        return value;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue queue;

    int num;
    cin >> num;

    while (num != -1) {
        queue.enqueue(num);
        cin >> num;
    }

    cout << "Dequeued elements:";
    while (!queue.isEmpty()) {
        int element = queue.dequeue();
        cout << " " << element;
    }
    cout << endl;

    return 0;
}
