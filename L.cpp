#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> window, arr;
int n, k;


int main(){
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int i = 0;
    for (; i < k; i++) window.push_back(arr[i]);
    sort(window.begin(), window.end());
    cout << window.front() << " ";
    for (; i < n; i++){
        window.erase(lower_bound(window.begin(), window.end(), arr[i-k]));
        window.insert(lower_bound(window.begin(), window.end(), arr[i]), arr[i]);
        cout << window.front() << " ";
    }
    return 0;
}

// Минимум на отрезке
//Двухсторонняя очередь, есть очередь на которой поддерживается инвариант
// очередь возврастающая, чтобы поддерживать инвариант который приходят, с конца очереди удалить
//все элементы больше него с конца очереди
