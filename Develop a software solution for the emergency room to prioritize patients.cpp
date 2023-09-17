#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient {
    int priority;
    string name;
    bool operator<(const Patient& other) const {
        return priority > other.priority;
    }
};

int main() {
    priority_queue<Patient> emergencyQueue;
    while (true) {
        int choice;
        cin >> choice;
        if (choice == 0) {
            break;
        } else if (choice == 1) {
            int priority;
            string name;
            cin >> priority >> name;
            emergencyQueue.push({priority, name});
        } else if (choice == 2) {
            if (!emergencyQueue.empty()) {
                Patient treatedPatient = emergencyQueue.top();
                emergencyQueue.pop();
                cout << "Patient with priority " << treatedPatient.priority << " and name " << treatedPatient.name << " has been treated." << endl;
            } else {
                cout << "Error: Queue is empty." << endl;
            }
        } else {
            cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
