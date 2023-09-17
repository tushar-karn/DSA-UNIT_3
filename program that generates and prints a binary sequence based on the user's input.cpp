
// You are assigned to design and implement a program that generates and prints a binary sequence based on the user's input.
// The program should utilize a queue data structure implemented using a linked list to efficiently generate and manage the binary sequence.

#include <iostream>
#include <queue>
using namespace std;

struct QueueNode {
    string data;
    QueueNode* next;
};

class BinarySequenceQueue {
private:
    QueueNode* front;
    QueueNode* rear;
public:
    BinarySequenceQueue() {
        front = rear = nullptr;
    }

    void enqueue(const string& value) {
        QueueNode* newNode = new QueueNode;
        newNode->data = value;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    string dequeue() {
        if (front == nullptr) {
            return "";
        }
        string value = front->data;
        QueueNode* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
        return value;
    }
};

void generateBinarySequence(int N) {
    BinarySequenceQueue queue;
    queue.enqueue("1");

    for (int i = 0; i < N; i++) {
        string current = queue.dequeue();
        cout << current << " ";
        queue.enqueue(current + "0");
        queue.enqueue(current + "1");
    }
}

int main() {
    int N;
    cin >> N;

    generateBinarySequence(N);

    return 0;
}
