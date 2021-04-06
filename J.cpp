#include <iostream>
#include <deque>
using namespace std;
deque<int> leftDeque, rightDeque;

void balance() {
    int difference = rightDeque.size() - leftDeque.size();
    if (difference > 0) {
        leftDeque.push_back(rightDeque[0]);
        rightDeque.pop_front();
    } else if (difference < 0) {
        rightDeque.push_front(leftDeque[leftDeque.size() - 1]);
        leftDeque.pop_back();
    }
}

//Гоблины
 int main() {
    int n;
    char sign;
    int number;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sign;
        if (sign == '-') {
            cout << leftDeque.front() << endl;
            leftDeque.pop_front();
        } else {
            cin >> number;
            if (sign == '+') rightDeque.push_back(number);
            else rightDeque.push_front(number);
        }
        balance();
    }
    return 0;
}