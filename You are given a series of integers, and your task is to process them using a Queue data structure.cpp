#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> q;
    int sum = 0;

    for (int i = 0; i < N; ++i) {
        int element;
        cin >> element;
        q.push(element);
        sum += element;
    }

    if (q.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << sum << endl;
    }

    return 0;
}
