// You have been given the responsibility to create a program for task management in a to-do list using a Queue data structure. This to-do list has a predefined limit for the number of tasks it can hold, and the tasks will be stored in a Queue that is implemented using a linked list

#include <iostream>
#include <string>
using namespace std;

struct TaskNode {
    string description;
    TaskNode* next;
};

class TaskQueue {
private:
    TaskNode* front;
    TaskNode* rear;
public:
    TaskQueue() {
        front = rear = nullptr;
    }

    void enqueue(const string& task) {
        TaskNode* newNode = new TaskNode;
        newNode->description = task;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    string getFrontTask() {
        if (front != nullptr) {
            return front->description;
        } else {
            return "Queue is empty";
        }
    }

    string getRearTask() {
        if (rear != nullptr) {
            return rear->description;
        } else {
            return "Queue is empty";
        }
    }
};

int main() {
    int N;
    cin >> N;
    cin.ignore();

    TaskQueue taskQueue;

    for (int i = 0; i < N; i++) {
        string task;
        getline(cin, task);
        taskQueue.enqueue(task);
    }

    cout << "Front Task: " << taskQueue.getFrontTask() << endl;
    cout << "Rear Task: " << taskQueue.getRearTask() << endl;

    return 0;
}
