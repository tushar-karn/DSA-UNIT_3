// You are working on a ticketing system for a popular music concert. The ticketing system uses a Queue data structure implemented using an array to manage incoming ticket requests. Each ticket request is represented by a unique identification number.



#include <iostream>
using namespace std;

class TicketQueue {
private:
    int* queue;
    int front;
    int rear;
    int capacity;

public:
    TicketQueue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = rear = -1;
    }

    void enqueue(int ticket) {
        if (rear == capacity - 1) {
            cout << "Queue is full. Cannot enqueue more tickets." << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = ticket;
    }

    void reverseFirstKElements(int k) {
        if (k < 1 || k > rear - front + 1) {
            cout << "Invalid value of K." << endl;
            return;
        }

        int start = front;
        int end = front + k - 1;

        while (start < end) {
            swap(queue[start], queue[end]);
            start++;
            end--;
        }
    }

    void printQueue() {
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int N, K;
    cin >> N >> K;

    TicketQueue ticketQueue(N);

    for (int i = 0; i < N; i++) {
        int ticket;
        cin >> ticket;
        ticketQueue.enqueue(ticket);
    }

    ticketQueue.reverseFirstKElements(K);
    ticketQueue.printQueue();

    return 0;
}
