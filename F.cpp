
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
int n, k;

bool check(int distance) {
    int lastCow = arr[0];
    int result = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] - lastCow >= distance) {
            result++;
            lastCow = arr[i];
        }

    }
    bool  answer = result >= k;
//    cout << "check " << distance << " result is " << answer;
    return answer;
}


int main() {
    int succesDistance = 1, failDistance, distance;
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    failDistance = arr[n - 1];
    while (failDistance - succesDistance > 1) {
        distance = (failDistance + succesDistance) / 2;
        if (check(distance)) succesDistance = distance;
        else failDistance = distance;
//        cout << "; current distances is " << succesDistance << " " << failDistance << endl;
    }
    cout << succesDistance << endl;
    return 0;
}

//На прямой расположены стойла, в которые необходимо расставить коров так, чтобы минимальное расcтояние
// между коровами было как можно больше.
//
//Формат ввода
//В первой строке вводятся числа N (2 < N ≤ 105) – количество стойл и K (1 < K < N ) – количество коров.
// Во второй строке задаются N натуральных чисел в порядке возрастания – координаты стойл (координаты не превосходят 109).
//
//Формат вывода
//Выведите одно число – наибольшее возможное допустимое расстояние.
