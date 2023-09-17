#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<string> waitlist;

    while (true) {
        int choice;
        cin >> choice;

        if (choice == 1) {
            string name;
            cin.ignore(); // Clear the newline character from previous input
            getline(cin, name);
            waitlist.push_back(name);
            cout << name << " has been added to the waitlist." << endl;
        }
        else if (choice == 2) {
            if (!waitlist.empty()) {
                cout << waitlist.front() << " has been removed from the waitlist." << endl;
                waitlist.pop_front();
            }
            else {
                cout << "Error: Waitlist is empty" << endl;
            }
        }
        else if (choice == 3) {
            if (!waitlist.empty()) {
                string moved_customer = waitlist.front();
                waitlist.pop_front();
                waitlist.push_back(moved_customer);
                cout << moved_customer << " has been moved to the back of the waitlist." << endl;
            }
            else {
                cout << "Error: Waitlist is empty" << endl;
            }
        }
        else if (choice == 4) {
            if (!waitlist.empty()) {
                cout << "Current waitlist:" << endl;
                for (const string& customer : waitlist) {
                    cout << customer << endl;
                }
            }
            else {
                cout << "Empty" << endl;
            }
        }
        else if (choice == 5) {
            cout << "Exiting" << endl;
            break;
        }
        else {
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
}
