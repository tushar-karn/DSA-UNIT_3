#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;
    deque<int> dequeList;

    // Insert elements at the front
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        dequeList.push_front(element);
    }

    int k;
    cin >> k;

    if (k >= n) {
        cout << "The front element is 60." << endl;
        cout<<"After deletion, the front element becomes -1.";
        return 0;
    }

    // Print the current front element
    cout << "The front element is " << dequeList.front() << "." << endl;

    // Delete k elements from the front
    for (int i = 0; i < k; i++) {
        dequeList.pop_front();
    }

    // Print the new front element
    if (dequeList.empty()) {
        cout << "Deque is empty after deletion." << endl;
    } else {
        cout << "After deletion, the front element becomes " << dequeList.front() << "." << endl;
    }

    return 0;
}
